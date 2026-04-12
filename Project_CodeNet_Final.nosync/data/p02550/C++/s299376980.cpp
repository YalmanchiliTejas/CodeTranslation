#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define PI 3.1415926535897932384626433832795028
#define INF (1<<29)
#define LINF (1LL<<60)
using namespace std;
using INT = long long;
using P = pair<int,int> ;

int main(){
    INT n,x,m;
    cin >> n >> x >> m;
    
    bool check = true;
    int cnt = 0;
    int start=0;
    INT total=0;
    INT ans=0;
    vector<INT> past;
    
    past.push_back(x);
    while(check){
        x = x*x % m;
        past.push_back(x);
        cnt++;
        if(cnt==n-1){
            rep(i,n){
                ans += past[i];
            }
            cout << ans;
            return 0;
        }
        rep(i,cnt){
            if(past[i]==x){
                check=false;
                start = i;
                for(int j=start;j<cnt;j++){
                    total += past[j];
                }
                break;
            }
        }
        
    }
    INT initial_part_total = 0;
    for(int i=0;i<start;i++){
        initial_part_total += past[i];
    }
    INT roop = (n - start)/(cnt - start);
    INT last_part = (n-start)-((cnt-start)*roop);
    
    int last_part_total=0 ;
    rep(i, last_part){
        last_part_total += past[i+start];
    }
    
    ans = initial_part_total + (total*roop) + last_part_total;
    cout << ans;
    
	return 0;
}

