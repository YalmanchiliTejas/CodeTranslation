#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n ;
    cin>>n ;
    long long arr[n] ;
    for(long long i = 0 ; i < n ; ++i)
        cin>>arr[i] ;
    sort(arr , arr + n) ;
    long long ans = 0 ;
       long long prev = arr[n/2] ;
       if(n % 2 == 0)
        prev = arr[n/2-1];
       map<long long , long long>mp ;
       mp[prev]++;
       long long now1 = 0 , now2 = n-1 ;
       long long x = 0 ;
       for(long long i = 0 ; i < n ; ++i)
       {
           if(mp[arr[i]] > 0)
           {
               mp[arr[i]]--;
               x = 1 ;
               continue;
           }
           if((i-x) % 2 == 1)
           {
               ans += abs(prev - arr[now1]);
               prev = arr[now1];
               now1++;
           }
           else
           {
               ans += abs(arr[now2] - prev) ;
               prev = arr[now2];
               now2--;
           }
       }
       prev = arr[n/2] ;
       if(n % 2 == 0)
        prev = arr[n/2-1];
       map<long long , long long>mp2 ;
       mp2[prev]++;
       now1 = 0 , now2 = n-1 ;
       x = 0 ;
       long long sum = 0 ;
       for(long long i = 0 ; i < n ; ++i)
       {
           if(mp2[arr[i]] > 0)
           {
               mp2[arr[i]]--;
               x = 1 ;
               continue;
           }
           if((i-x) % 2 == 0)
           {
               sum += abs(prev - arr[now1]);
               prev = arr[now1];
               now1++;
           }
           else
           {
               sum += abs(arr[now2] - prev) ;
               prev = arr[now2];
               now2--;
           }
       }
    ans = max(ans , sum);
    return cout<<ans<<"\n" , 0 ;
}
