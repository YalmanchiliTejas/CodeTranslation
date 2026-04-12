//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int low[123][123],req[12][12],remain[123][123];
int main(){
    std::ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    int i,j;
    f(i,1,a+1){
    	f(j,1,b+1){
    		cin>>req[i][j];
    	}
    }
    rep(i,101){
    	rep(j,101){
    		remain[i][j]=1;
    		low[i][j]=0;
    	}
    }
    int val,p,q;
    f(i,1,a+1){
    	f(j,1,b+1){
    		rep(p,101){
    			rep(q,101){
    				val=i*p+j*q;
    				if(req[i][j]>val){
    					low[p][q]=max(low[p][q],req[i][j]-val);
    				}
    			}
    		}
    	}
    }
    int flag;
    f(i,1,a+1){
    	f(j,1,b+1){
    		flag=0;
    		rep(p,101){
    			rep(q,101){
    				val=i*p+j*q+low[p][q];
    				if(val==req[i][j]){
    					remain[p][q]=1;
    					flag=1;
    				}
    				
    			}
    		}
    		if(flag==0){
    			cout<<"Impossible"<<endl;
    			return 0;
    		}
    	}
    }
    int edg=0;
    cout<<"Possible"<<endl;
    cout<<202<<" "<<10401<<endl;
    cout<<201<<" "<<1<<" X"<<endl;
    edg++;
    f(i,1,100){
    	edg++;
    	cout<<i<<" "<<i+1<<" X"<<endl;
    }
    edg++;
    cout<<200<<" "<<202<<" Y"<<endl;
    f(i,101,200){
    	edg++;
    	cout<<i<<" "<<i+1<<" Y"<<endl;
    }
    f(i,1,101){
    	f(j,1,101){
    		edg++;
    		if(remain[i][j]==1)
    			cout<<i<<" "<<200-j+1<<" "<<low[i][j]<<endl;
    	}
    }
    f(i,1,101){
    	edg++;
    	if(remain[0][i]==1)
    		cout<<201<<" "<<200-i+1<<" "<<low[0][i]<<endl;
    }
    f(i,1,101){
    	edg++;
    	if(remain[i][0]==1)
    		cout<<i<<" "<<202<<" "<<low[i][0]<<endl;
    }
    edg++;
    cout<<201<<" "<<202<<" "<<low[0][0]<<endl;
    //cout<<edg<<endl;
    cout<<201<<" "<<202<<endl;

    return 0;  
    
}

