#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<long long >where;
int n, k, a, b;
long long solve(long long start , long long end){
    long long  r = upper_bound(where.begin(), where.end(), end)-where.begin();
    long long l = lower_bound(where.begin(), where.end(), start)-where.begin();
    
    long long  aveng = r - l;
   
    if(start == end){
        if(aveng)return 1 * aveng * b;
        return a;
    }
    
    
    long long ch1 ;
    if(aveng)
    ch1 = (end - start + 1) * aveng * b;
    else return  a;
   
    long long ch2 = solve(start, (end + start)/ 2) + (solve((end + start)/ 2 + 1, end));
    

    return min(ch1, ch2);
    
}
int main(void){
 int n;
 cin >> n;
 if(n >= 30)cout << "Yes";
 else cout << "No";
}