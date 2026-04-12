#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
using namespace std;



int long long solve(int n,int long long x){
    if(x==0){return 0;}
    if(n==0){return 1;}
    if(x<=pow(2,(int long long)n+1)-2) return solve(n-1,x-1);
    
    return solve(n-1,x-pow(2,(int long long)n+1)+1)+pow(2,n);
}


int main(){
    int a;
    int long long b;
    cin>>a>>b;
    int long long ans =solve(a,b);
    cout<<ans<<endl;
return 0;
}
