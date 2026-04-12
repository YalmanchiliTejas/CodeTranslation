#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h.at(i);
    }
    int count = 1;
    int flag = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(h.at(i) < h.at(j)){
                flag = 0;
            }
        }
        if(flag == 1){
            count++;
        }
        flag = 1;
    }
    cout << count;
}