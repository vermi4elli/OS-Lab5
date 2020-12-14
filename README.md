# OS-Lab5
## Task
The task was to optimize given code in terms of memory calls. The code was given on variants. Mine is: 21 (number of my student's record-book) mod 15 (amount of variants)
 + 1 (to eliminate the possibility of the variant being equal to 0) = __7__.
## The unoptimized program's code
~~~
static void Main(string[] args) {
    int[] Vector = new int[2];
    int res = 0;

    for (int j = 500000000; j > 0; j--)
    {
        Vector [0]++;
        Vector [0]++;
    }

    Vector[1] = Vector[0];
    
    for (int j = 0; j < 10000000; j++)
    {
        Vector [0]--;
        Vector [0]--;
    }

    Vector[1] = Vector[0];
    Console.WriteLine(Vector[0]);
}
~~~
The given code is in C#, so I rewrote the unoptimized C# code into the unoptimized C++ code and also added the lines to calculate the amount of time it was working for:
~~~
int main() {
    auto beginning = std::chrono::high_resolution_clock::now();

    int* Vector = new int[2]{ 0, 0 };
    int res = 0;
    for (int j = 500000000; j > 0; j--)
    {
	Vector[0]++;
	Vector[0]++;
    }

    Vector[1] = Vector[0];

    for (int j = 0; j < 10000000; j++)
    {
	Vector[0]--;
	Vector[0]--;
    }
    Vector[1] = Vector[0];

    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = ending - beginning;
    cout << "Took " << diff.count() << "s to deal with the unoptimal task, phew\nBy the way, Vector[0] = Vector[1] = " << Vector[1] << "\n" << endl;
	    
    return 0;
}
~~~
## The unoptimized program's time data
> Speaking of performance, I decided to check it in many tries, to be exact, in 20 tries. So, the final version of the program is in the repo in main.cpp.

The unoptimized program's time data is the time it spent in average (as seen in the picture below) as of *size* tries.
![The unoptimized program's time data](/images/unoptimized.jpg "The unoptimized program's time data")
## The optimized program's code
~~~
int main() {
    auto beginning = std::chrono::high_resolution_clock::now();
    
    int* Vector = new int[2]{ 0, 0 };
    int res = 0;
    for (int j = 500000000; j > 0; j--)
    {
        Vector[0] += 2;
    }

    for (int j = 0; j < 10000000; j++)
    {
        Vector[0] -= 2;
    }
    Vector[1] = Vector[0];
    
    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = ending - beginning;
    cout << "Took " << diff.count() << "s to deal with the unoptimal task, phew\nBy the way, Vector[0] = Vector[1] = " << Vector[1] << "\n" << endl;
    
    return 0;
}
~~~
## The optimized program's time data
The optimized program's time data is the time it spent in average (as seen in the picture below) as of *size* tries.
![The optimized program's time data](/images/optimized.jpg "The optimized program's time data")
## The changes
+ First of all, I changed the two calls like ```Vector[0]++``` or the opposite, decrement, to the ```Vector[0]+=2```, which is more optimal in a way it eliminates the need
to make the memory call twice instead of just one.
+ Then, I changed the ```int j = ...``` in the ```for``` loops to a ```register int j = ...``` as it should suggest the compiler to store this value in the registers.
+ Finally, I got rid of the unneccessary memory call in between of the two ```for``` loops - it is not beeing called anywhere but straight after it was done second time after the second loop.
## The final result
The results I've got are quite understandable, we've reached our goal of optimizing the program:
![The result time data](/images/result.jpg "The result time data")
But to make things even more dramatic, I've increased the amount of loop steps by a couple orders of magnitude:
![The dramatic result time data](/images/dramatic_result.jpg "The dramatic result time data")
