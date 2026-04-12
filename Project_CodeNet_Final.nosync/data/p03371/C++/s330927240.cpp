#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll w=min(a+b,2*c);
    int v=min(x,y);

    ll sum=w*v;
    
    if(x>y){
        sum+=(x-y)*a;
        
        ll tmp=sum;
        
        if(a+b<2*c){
            int cnt=y;
            while(tmp<=sum && cnt>=0){
                sum=tmp;
                tmp=sum-a-b+2*c;
                cnt--;
            }
        }else{
            int cnt=x-y;
            while(tmp<=sum && cnt>=0){
                sum=tmp;
                tmp=sum-a+2*c;
                cnt--;
            }
        }

    }else{
        sum+=(y-x)*b;
        
        ll tmp=sum;

        if(a+b<2*c){
            int cnt=x;
            while(tmp<=sum && cnt>=0){
                sum=tmp;
                tmp=sum-a-b+2*c;
                cnt--;
            }
        }else{
            int cnt=y-x;
            while(tmp<=sum && cnt>=0){
                sum=tmp;
                tmp=sum-b+2*c;
                cnt--;
            }
        }
    
    }

    cout << sum << endl;
}