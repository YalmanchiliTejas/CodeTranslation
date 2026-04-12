#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int > y;
    int t[n];
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    sort(t,t+n);
    int mx=t[n-1];
    int co=0;
    for(int i=1;i<=100000;i++){
        if(mx%i==0){
            y.push_back(i);
            co++;
        }
    }

    int k=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=k;j<co;j++){
            if(t[i]<=y[j]){
                ans+=(y[j]-t[i]);
                break;
            }
            else {
                k++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

