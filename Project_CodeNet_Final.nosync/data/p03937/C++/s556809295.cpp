#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}

int main(){
    int h,w;
    in(h,w);
    vector<vector<char>> vec(h,vector<char>(w));
    rep(y,h){
        rep(x,w){
            in(vec[y][x]);
        }
    }
    int ans=1;
    queue<pair<int,int>> next;
    pair<int,int> start,goal;
    vector<vector<bool>> checked(h,vector<bool>(w,false));
    start=make_pair(0,0);
    goal=make_pair(w-1,h-1);
    next.push(start);
    int x,y;
    checked[0][0]=1;
    while(!next.empty()){
        x=next.front().first;
        y=next.front().second;
        next.pop();
        //debug(x,y);
        if(x==goal.first&&y==goal.second){
            if(x-1>=0&&!checked[y][x-1]&&vec[y][x-1]=='#'){
                ans=0;
                break;
            }
            if(y-1>=0&&!checked[y-1][x]&&vec[y-1][x]=='#'){
                ans=0;
                break;
            }
            break;
        }
        if(x+1<w&&!checked[y][x+1]&&vec[y][x+1]=='#'){
            next.push(make_pair(x+1,y));
            checked[y][x+1]=true;
        }
        if(y+1<h&&!checked[y+1][x]&&vec[y+1][x]=='#'){
            next.push(make_pair(x,y+1));
            checked[y+1][x]=true;
        }
        if(x-1>=0&&!checked[y][x-1]&&vec[y][x-1]=='#'){
            ans=0;
            break;
        }
        if(y-1>=0&&!checked[y-1][x]&&vec[y-1][x]=='#'){
            ans=0;
            break;
        }
        if(next.size()>=2){
            ans=0;
            break;
        }
    }
    cout<<(ans?"Possible":"Impossible")<<endl;
}