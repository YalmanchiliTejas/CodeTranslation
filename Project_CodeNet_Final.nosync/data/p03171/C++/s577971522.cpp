#include<bits/stdc++.h>
using namespace std;

const int N = 3001;
vector<int> arr(N); 
int n; 
vector< vector<long int> > memo(3001, vector<long int> (3001,-1)); 


long int find(int i, int j)
{  
    if( i > j ) return 0 ;
    
    long int &res = memo[i][j];
    if(res != -1) return res;
    
    res = arr[i] - find(i+1,j);
    res = max(res,arr[j]-find(i,j-1));
    
    return res; 
}
void solve( )
{
    
   cin >> n ;
   for(int i = 0 ; i < n ; i ++) cin >> arr[i];
   
   cout <<  find(0,n-1); 
  

}

int main()
{   
    
    
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);


    solve(); 
    return 0;
}


