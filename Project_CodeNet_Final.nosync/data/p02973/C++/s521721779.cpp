#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 5;
long long arr[maxn];
int solve(int n) 
{ 
    multiset<long long> last; 
    for (int i = 0; i < n; i++) { 
        multiset<long long>::iterator it = last.lower_bound(arr[i]); 
        if (it == last.begin()) 
            last.insert(arr[i]); 
  
        else { 
            it--;
            last.erase(it); 
            last.insert(arr[i]); 
        } 
    } 
    return last.size();
} 

int main(int argc, char const *argv[])
{
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }cout << solve(n) <<endl;

    return 0;
}