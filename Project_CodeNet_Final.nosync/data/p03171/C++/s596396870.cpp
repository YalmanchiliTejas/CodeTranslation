#include<iostream>
using namespace std ;
#define ll long long int 
ll arr[3001][3001] , visi[3001][3001] , grr[10000] ;


ll find(ll i , ll j , ll val )
{
    if(visi[i][j]==1)
    {
        return  arr[i][j] ;
    }
    
    if( i==j)
    {
        if(val == 0)
        {
            arr[i][j]= grr[i] ;
        }else
        {
            arr[i][j] = -grr[i] ;
        }
        
        visi[i][j] =1 ;
        return  arr[i][j] ;
    }
    
    
    if(val==0 )
    {
        arr[i][j] = max(grr[i] + find(i+1 , j,1) , grr[j] + find(i, j-1 , 1)) ;
    }else
    {
        arr[i][j] = min(find(i,j-1 ,0) - grr[j] , find(i+1 , j , 0) - grr[i]) ;
    }
    
    
    visi[i][j] =1 ;
    return arr[i][j] ;
    
}
 
int main()
{
    ll n ;
    cin >> n ;
    for(ll i= 0 ; i < n ;i++)
    {
        cin >> grr[i] ;
    }
    
    
    cout <<find(0 , n-1 , 0 ) ;
    return 0 ;
    
    
}