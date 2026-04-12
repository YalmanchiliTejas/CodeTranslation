#include<iostream>
#include<cmath>
#include<map>
#include<deque>
#include<string>
#include<algorithm>

#define all(x) (x).begin(),(x).end()
#define puts(x) cout<< x << endl;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fore(i,a) for(auto i:a)
#define ll long long
using namespace std;
ll m,n;
int main(){
    cin>>m>>n;
    if(m==n){
        puts("Yes");
    }else{
        puts("No");
    }
}