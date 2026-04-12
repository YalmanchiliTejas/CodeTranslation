#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> P;
typedef pair<ll, ll> PL;
const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}
 
ll a[100000+10];
ll ans[200000+100];
int lp,rp;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    ans[100010] = a[0];
    ans[100011] = a[n-1];
    lp = 100010;
    rp = lp+1;
    ll sp=1,bp=n-2;
    ll mem1,mem2,mem3,mem4,mems,memb;
    for(int i = 2; i < n; i++){
        mem1 = abs(ans[lp]-a[sp]);
        mem2 = abs(ans[rp]-a[sp]);
        mem3 = abs(ans[lp]-a[bp]);
        mem4 = abs(ans[rp]-a[bp]);
        mems = max(mem1,mem2);
        memb = max(mem3,mem4);

        if(mems >= memb){
            if(mem1 >= mem2){
                --lp;
                ans[lp] = a[sp];
                
            }
            else{
                ++rp;
                ans[rp] = a[sp];
            }
            ++sp;
        }
        else{
            if(mem3 >= mem4){
                --lp;
                ans[lp] = a[bp];
                
            }
            else{
                ++rp;
                ans[rp] = a[bp];
            }
            --bp;
        }
    }

    ll an=0;
    for(int i = lp; i < rp; i++){
        an += abs(ans[i]-ans[i+1]);
    }
    cout << an << endl;
}