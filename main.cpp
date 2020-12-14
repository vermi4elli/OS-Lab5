#include <iostream>
#include <chrono>
using namespace std;

double unoptimal() {
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
    return diff.count();
}
double optimal() {
    auto beginning = std::chrono::high_resolution_clock::now();
    
    int* Vector = new int[2]{ 0, 0 };
    int res = 0;
    for (register int j = 500000000; j > 0; j--)
    {
        Vector[0] += 2;
    }

    Vector[1] = Vector[0];

    for (register int j = 0; j < 10000000; j++)
    {
        Vector[0] -= 2;
    }
    Vector[1] = Vector[0];

    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = ending - beginning;
    cout << "Took " << diff.count() << "s to deal with the optimal task, phew\nBy the way, Vector[0] = Vector[1] = " << Vector[1] << "\n" << endl;
    return diff.count();
}

int main()
{
    double unOp = unoptimal();
    double Op = optimal();

    cout << "The optimal variant is " << unOp / Op << " times more optimal than the unoptimal" << endl;
    return 0;
}
