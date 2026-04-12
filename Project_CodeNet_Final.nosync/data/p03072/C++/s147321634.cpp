#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int num;
    num = 0;
    int max;
    max = 0;
    for(int i=0; i<n; i++){
        if(h[i]>=max){
            max = h[i];
        }
        if(h[i]>=max){
            num++;
        }
    }
    cout << num << endl;
}

