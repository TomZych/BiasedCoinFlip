#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

bool flip_coin(double p){
    return static_cast<double>(rand())/RAND_MAX < p;
}
void biasedCoinFlip(int n, double p, int m){
    for (int trial = 1; trial <= m; ++trial){
        int heads = 0;
        for (int i = 0; i < n; ++i){
            if (flip_coin(p)){
                ++heads;
            }
        }
        cout << left << setw(10) << p
             << setw(10) << n
             << setw(10) << trial
             << setw(10) << heads << endl;
    }
    cout << string(50, '-') << endl;
}

int main(){
    srand(static_cast<unsigned int>(time(0)));

    int n;
    double p;
    const int m = 10;

    cout << "Enter values of flips (n): ";
    cin >> n;
    cout << "Enter probability of getting heads (p): ";
    cin >> p;
    cout << "\n";

    cout << left << setw(10) << "Prob"
         << setw(10) << "Flips"
         << setw(10) << "Trial"
         << setw(10) << "Heads" << endl;
    cout << string(50, '-') << endl;
    biasedCoinFlip(n, p, m);

    return 0;
}