#include<bits/stdc++.h>
using namespace std;

int main(void){
    while(true){
        int n, min=10000, max=-1, sum=0;
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;++i){
            int s;
            cin >> s;
            sum += s;
            max = (max > s)? max: s;
            min = (min < s)? min: s;
        }
        cout << (sum-max-min)/(n-2) << endl;
    }
}
