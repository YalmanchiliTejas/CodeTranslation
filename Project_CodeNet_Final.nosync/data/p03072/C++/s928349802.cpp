#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, max, kosuu;
    kosuu = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n;i++){
        vec.at(i) = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vec.at(i);
        max = *max_element(vec.begin(), vec.end());
        if(max == vec[i]){
            kosuu += 1;
        }
    }
    cout << kosuu;

    return 0;
}