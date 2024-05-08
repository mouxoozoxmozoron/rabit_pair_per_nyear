#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

//iterative aprach to culculate fibbonacci umber
int fibbonaciterative(int n){
    if (n <=1)
        return n;
    
    int a = 0, b = 1, c;
    for (int i =2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

//using general formulae
int fibbonacciusingfromulae(int n){
    double phi = (1 + sqrt(5)) / 2;
    return round(pow (phi, n)/ sqrt(5));
}

int main(){
    int n;

    cout << "enter the number of mounth";
    cin >> n;


    //time measurement
    auto startiterative = high_resolution_clock::now();
    int resultiterative = fibbonaciterative(n);
    auto stopiterative = high_resolution_clock::now();
    auto durationiterative = duration_cast<microseconds>( stopiterative - startiterative );


    //formulae based culculation
     auto startformulae = high_resolution_clock::now();
    int resultformulae = fibbonacciusingfromulae(n);
    auto stopformulae = high_resolution_clock::now();
    auto durationformulae = duration_cast<microseconds>( stopformulae - startformulae );

    cout << "number of rabits pairs after" <<n <<"months using iterativve method is" <<resultiterative <<endl;
    cout << "time taken using itterative method is " <<durationiterative.count() <<"microseconds" <<endl;
    cout << "number of pair of rabit after "<<n <<"using formulae is" << resultformulae <<endl;
    cout <<"time taken using formulae is" << durationformulae.count() <<"micro seconds" <<endl;

}

//READ ME
// compile the code first       g++ rabit.cpp -o rabit
//run the code now        ./rabit
