#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
const int INF = 1<<30;
const int mod= int(1e9)+7;

int main(){
    while(1){
        int n;cin >>n;
        if(n==0)break;
        int k=n-2;
        int sum=0;
        int mx=-1;int mint=INF;
        for (int i = 0; i < n; ++i) {
            int s;cin >>s;
            mx=max(mx,s);
            mint=min(mint,s);
            sum+=s;
        }
        sum-=(mint+mx);
        cout <<sum/k<<endl;
    }
}

