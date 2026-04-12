//124B
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
int main(void){
    int n=0;
    int cnt =1;
    bool flag = true;
    cin >> n;
    vector<int>L(n,0);
    rep(i, n) cin >> L[i];
    for(int i=n-1; i>=1; i--){
        flag = true;
        for(int j=i; j>=0; j--){
            if(L[i]<L[j]){
                flag=false;
                break;
            }
        }
        if(flag==true) cnt+=1;
    }
    cout << cnt << endl;
}