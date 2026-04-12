#include<bits/stdc++.h>
/**
* ????????????temp.
*/
#define int long long int
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repm(a,b,c) for(int a=(b-1);a>=c;a--)
#define pb push_back
#define str string
#define sf(a) scanfs("%d",&a)
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) (v).begin(), (v).end()

using namespace std;

const int INF = 1e18 + 9;
const int Mod = 1e9 + 7;
inline int replac(str s){double ans=0;rep(i,0,s.length()){ans+=(s[i]-'0')*pow(10,s.length()-i-1);}return (int)ans;}
typedef pair<int,int> pii;
typedef pair<int,char> pic;
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m[100005];stack<pii> num;
    while(1){
    cin >> n;
    if(n==0)break;
    rep(i,0,n){
        cin >> m[i];
    }
    int mae=m[0],len=1;
    rep(i,1,n){
        if(mae!=m[i]){
            if(i%2){
                while(!num.empty()){
                    pii y=num.top();
                    if(y.second!=m[i]){
                        num.pop();
                        len+=y.first;
                    }else{
                        break;
                    }
                }
                num.push(make_pair(len+1,m[i]));
                len=0;
            }else{
                if(len)num.push(make_pair(len,mae));
                len=1;
                if(i==(n-1)){
                    num.push(make_pair(len,m[i]));
                }
            }
        }else{
            len++;
            if(i==(n-1)){
               // cout << "a";
                num.push(make_pair(len,m[i]));
            }
        }
        mae=m[i];
    }
    int ans=0;
    while(!num.empty()){
        pii a=num.top();num.pop();
        //cout << a.first << endl;
        if(a.second==0){
            //cout << a.first << endl;
            ans+=a.first;
        }
    }
    if(n==1&&m[0]==0)ans++;
    cout << ans << endl;
    }
    return 0;
}