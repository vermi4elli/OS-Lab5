# OS-Lab5
## Task
The task was to optimize given code in terms of memory calls. The code was given on variants. Mine is: 21 (number of my student's record-book) mod 15 (amount of variants)
 + 1 (to eliminate the possibility of the variant being equal to 0).
## The unoptimized program's code
~~~
static void Main(string[] args)
        {
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
~~~
## The unoptimized program's time data
The unoptimized program's time data is the time it spent in average (as seen in the picture below).
