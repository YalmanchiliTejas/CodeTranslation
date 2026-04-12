#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> numbers(n); for (int i=0;i<n;i++){cin >> numbers[i];}
    vector<long long> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end());
    long long one_before, one_after;
    one_before = sorted_numbers[n/2 - 1];
    one_after = sorted_numbers[n/2];

    for (auto k : numbers){
        if (k <= one_before){
            cout << one_after << endl;
        } else {
            cout << one_before << endl;
        }
    }

    return 0;
}