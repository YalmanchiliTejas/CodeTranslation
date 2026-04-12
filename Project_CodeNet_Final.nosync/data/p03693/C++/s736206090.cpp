#include<bits/stdc++.h>
using namespace std;
#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define lrp(i,n) for(long long i=0;i<n;i++)
#define lrep(i,m,n) for(long long i=m;i<=n;i++)
#define ll long long
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define abs(a,b) (a-b>0?a-b:b-a)
#define size size()

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int a;
    a=100*r+10*g+b;
    if(a%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}





