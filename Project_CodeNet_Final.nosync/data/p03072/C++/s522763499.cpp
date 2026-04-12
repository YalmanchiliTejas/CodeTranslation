#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mt(n);
    for (int i=0; i < n; i++){
        int l_i;
        cin >> l_i; 
        mt[i] = l_i;
    }
    int sum = 1;
    for (int i=1; i< n; i++){
        bool check = true;
        for (int j=0; j < i; j++){
            if ( mt[i] < mt[j]){
                check = false;
                break;
            }
        }
        if (check == true){
            sum = sum + 1;
        }

    }



    cout << sum << endl;
}