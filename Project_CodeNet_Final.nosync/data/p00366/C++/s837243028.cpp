#include"bits/stdc++.h"

using namespace std;

long long gcd(int x,int y)
{
    if(y>x) swap(x,y);
    if(y==0) return x;
    return gcd(y,x%y);
}

int main()
{
    int n;
    cin >> n;
    int t[n];
    int m=0;
    for(int i=0;i<n;i++){
        cin >> t[i];
        m=max(m,t[i]);
    }
    vector<int> v;
    for(int j=1;j<=m;j++)
        if(m%j==0){
            v.push_back(j);
        }
    v.push_back(m+10);
    long long sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=(int)v.size()-1;j++){
            if(abs(t[i]-v[j])<=abs(t[i]-v[j+1])&&t[i]<=v[j]){
                sum+=abs(t[i]-v[j]);
                break;
            }
        }
    }
    cout <<sum << endl;
    return 0;
}


