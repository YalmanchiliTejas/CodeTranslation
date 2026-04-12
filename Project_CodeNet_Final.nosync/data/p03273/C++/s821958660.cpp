/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Code author: Saurabh Singhal
Code copy karne vaale tera muh kaala
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ppb pop_back

using namespace std;
typedef long long int ll;
typedef vector<int> vi_t;
typedef vector<ll> vll_t;
int t=1;
vll_t a,b;
int  main(){
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
	// #endif
    int h,w;
    cin>>h>>w;
    char grid[h][w];
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		cin>>grid[i][j];
    	}
    }
    unordered_map<int,bool>row,column;
    for(int i=0;i<h;i++){
    	row[i]=false;
    }
    for(int i=0;i<w;i++){
    	column[i]=false;
    }
    for(int i=0;i<h;i++){
    	int count=0;
    	for(int j=0;j<w;j++){
    		if(grid[i][j]=='#'){
    			count++;
    			break;
    		}
    	}
    	if(count==0){
    		row[i]=true;
    		//cout<<"i="<<i<<endl;
    	}
    }
    for(int i=0;i<w;i++){
    	int count=0;
    	for(int j=0;j<h;j++){
    		if(grid[j][i]=='#'){
    			count++;
    			break;
    		}
    	}
    	if(count==0){
    		column[i]=true;
    		//cout<<"j="<<i<<endl;
    	}
    }
    for(int i=0;i<h;i++){
    	bool flag=false;
    	for(int j=0;j<w;j++){
    		if(!row[i]&&!column[j]){
    			cout<<grid[i][j];
    			flag=true;
    		}
    	}
    	if(flag){
    		cout<<endl;
    	}
    }
}