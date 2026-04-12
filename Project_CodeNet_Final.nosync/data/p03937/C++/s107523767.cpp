#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<utility>
#include<set>
#include <queue>
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
#define pb(x) push_back(x)
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
using namespace std;
vector<string> a(10);
int vis[10][10];
int main()
{
    int i,j,h,w;
    ios_base :: sync_with_stdio(false); 

    cin>>h>>w;
    F(i,0,h){
        cin>>a[i];
    }

    j = 0;
    F(i,0,h){
        if(a[i][j] == '.'){
            cout<<"Impossible"<<endl;
            return 0;
        }
        while(j<w){
            if(a[i][j] == '.'){
                j--;
                break;
            }
            vis[i][j] =1;
            j++;
        }
        j = min(j,w-1);
    }

    F(i,0,h){
        F(j,0,w){
            if(a[i][j] == '#' && vis[i][j] ==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }


    cout<<"Possible"<<endl;
    return 0;

}