#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define PI 3.1415926535897932384626433832795
using namespace std;

int main(){
    string s;
    cin>>s;
    int a[3];
    int sum=0;
    f(i,3){
        a[i]=s[i]-65;
        sum= sum+a[i];
    }
    if(sum==1 || sum==2){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    return 0;
}

