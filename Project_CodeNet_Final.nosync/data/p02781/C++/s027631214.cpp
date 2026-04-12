#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pref_trie;
typedef tree<long int,null_type,less<long int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef cc_hash_table<long int,long int, hash<long int>, equal_to<long int>, direct_mask_range_hashing<long int>, 
hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>> ht;

#define int long long 

const int M = 200;

int dp[M][M][2];   
int K; 
  
int countInRangeUtil(int pos, int cnt, int tight, vector<int> num) { 
    if (pos == num.size()) { 
        if (cnt <= K) 
            return 1; 
        return 0; 
    } 
  
    if (dp[pos][cnt][tight] != -1) 
        return dp[pos][cnt][tight]; 
  
    int ans = 0; 
   int limit = (tight ? 9 : num[pos]); 
  
    for (int dig = 0; dig <= limit; dig++) { 
        int currCnt = cnt; 
  
        if (dig != 0) 
            currCnt++; 
  
        int currTight = tight; 
  
        if (dig < num[pos]) 
            currTight = 1; 
  
        ans += countInRangeUtil(pos + 1, currCnt,currTight, num); 
    } 
    return dp[pos][cnt][tight] = ans; 
} 
  
int countInRange(string x) { 
    vector<int> num; 
    while (x.size()) { 
        num.push_back(x[x.size()-1] - '0'); 
        x.pop_back();
    } 
    reverse(num.begin(), num.end()); 
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
} 

int32_t main(){
   IOS;
 //    #ifndef ONLINE_JUDGE
 //        freopen("in.txt",  "r",  stdin);
 //        freopen("out.txt", "w", stdout);
 //    #endif
      
      string R;
      cin>>R;
      cin>>K;

       int val = countInRange(R);
      K--;
       int val2 = countInRange(R);

      cout<<val-val2; 

   return 0;
}