#include <iostream>
#include<algorithm>
#include<set>
#include<iterator>
#include<map>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define fo(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int inf = (1e18)+7;
const int neginf = -1*((int)1e17 ) + 7 ; 

int32_t main() {
    fastio
        
    int n,m;
    cin>>n>>m;
    
    
    char arr[n][m];
    bool row[110]={false},colm[110]={false};
    char ch;
    fo(i,n){
        fo(j,m){
            cin>>ch;
            if(ch=='#')
            {
                row[i] = 1;
                colm[j] = 1;
            }
        arr[i][j]= ch;
        }
    }
    
    
    
    
    for(int i=0;i<n;++i)
    {
        if(row[i]){
        for(int j=0;j<m;++j)
        {
            if(colm[j])
                cout<<arr[i][j];
        }
        cout<<endl;
        }
        
        
    }
    
     
    
    
    

        
        
        
    
            
        
       
        
        
        
    
     
    
    
	return 0;
}
