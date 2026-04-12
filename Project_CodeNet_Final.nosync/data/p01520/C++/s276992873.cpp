#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

#define LP(i,n) for(int i=0;i<n;i++)
#define Mset(x,v) memset(x,v,sizeof(x))
#define INF INT_MAX

using namespace std;
using LL=long long;

int main(){
    int n,t,e,x,f=1;
    cin>>n>>t>>e;
    LP(i,n){
        cin>>x;
        int j=1;
        while(x*j<=t+e){
            if(x*j>=t-e&&f==1){
                cout<<i+1<<endl;
                f=0;
            }
            j++;
        }
    }
    if(f) cout<<-1<<endl;
    return 0;
}

