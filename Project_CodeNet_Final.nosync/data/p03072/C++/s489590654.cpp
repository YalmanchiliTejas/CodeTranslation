#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>myvector;
    int x;
    int i;
    for(i = 0; i < n; i++){
            cin >> x;
            myvector.push_back(x);
    }
    int a = myvector[0];
    int H = 1;
    for(i = 1; i < n; i++){
        if(myvector[i] >= a){
            a = myvector[i];    
            H += 1;
        }
    }
    cout << H;
}