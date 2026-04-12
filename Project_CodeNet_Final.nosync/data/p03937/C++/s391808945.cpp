#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define ll long long 
#define fr(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define inf (1<<31)
#define xx first
#define yy second

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int h,w;
	cin>>h>>w;
	char a[h][w];
	fr(i,h){
	    fr(j,w){
	        cin>>a[i][j]    ;
	    }
	}
	int x,y,f=1;
	x=0,y=0;
	a[0][0]='.';
	while(f && !(x==h-1 && y==w-1)){
	    if(x==h-1){
	        a[x][y+1]='.';
	        y++;
	    }    
	    else if(y==w-1){
	        a[x+1][y]='.';
	        x++;
	    }    
	    else{
	        if(a[x+1][y]=='#'){
	            a[x+1][y]='.'; 
	            x++;
	        }
	        else if(a[x][y+1]=='#'){
	             a[x][y+1]='.';
	             y++;
	        }
	        else
	            f--;
	       
	    }
//	    cout<<x<<' '<<y;
	}    
	int l=0;    
	    fr(i,h){
	        fr(j,w){
	            if(a[i][j]!='.'){
	             //   cout<<a[i][j];
	                l--;
	            }
	           // cout<<endl;    
	        }
	    }
	 if(l)
	    cout<<"Impossible";
	 else
	    cout<<"Possible";
	
	return 0;
}