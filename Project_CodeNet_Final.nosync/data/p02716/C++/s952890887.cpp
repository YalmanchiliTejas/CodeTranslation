#include <iostream>
#include<bits/stdc++.h>
using namespace std ;
const int INF=1e9+5;
#define  IO cin.tie(0); cin.sync_with_stdio(0)
typedef  long long ll ;


int main(){
    IO;
     int n ;
     cin>>n ;
     ll best_even_begin_not_token=0,best_odd_begin_not_token=0,best_even_begin_token=-INF,best_odd_begin_token=-INF;
     ll arr[n+10];
     for(int i =0 ; i < n ; i++)cin>>arr[i];
     for(int i=n;i<n+6;i++)arr[i]=0;
     for(int i =0 ; i< n ; i+=2){
         ll temp_best_even_begin_not_token=best_even_begin_not_token,temp_best_odd_begin_not_token=best_odd_begin_not_token,
         temp_best_even_begin_token=best_even_begin_token,temp_best_odd_begin_token=best_odd_begin_token;

           best_even_begin_not_token=temp_best_even_begin_not_token+arr[i];
           best_odd_begin_not_token=max(temp_best_odd_begin_not_token,temp_best_even_begin_not_token)+arr[i+1];
           best_even_begin_token=max(temp_best_even_begin_token,temp_best_even_begin_not_token)+arr[i+1];
           best_odd_begin_token=max({temp_best_odd_begin_token,temp_best_even_begin_token,temp_best_odd_begin_not_token})+arr[i+2];
     }
     if(n%2==0)cout<<max(best_even_begin_not_token,best_odd_begin_not_token);
     else cout<<max(best_even_begin_token,best_odd_begin_token);
    return 0;
}
