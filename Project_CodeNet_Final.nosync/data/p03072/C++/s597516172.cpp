#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maximum = 0;
    int total = 0;
    for (int i=0;i<n;i++){
        if (arr[i] >= maximum){
            total++;
            maximum = arr[i];
        }
    }
    cout << total;
}

