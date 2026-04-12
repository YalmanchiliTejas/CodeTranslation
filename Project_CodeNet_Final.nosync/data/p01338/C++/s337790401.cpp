#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)
#define each(e,c) for(auto&e:c)

typedef vector<int> vi;
typedef map<int, int> mii;

int const score[] = { 0, 0, 60, 70, 80 };
int eval(int n){
    int s = 0;
    rep(i,5){
        s+=score[n&0b111];
        n>>=3;
    }
    return s;
}

int flip(int n,int f){
    f<<=2;
    int r=0;
    rep(i,5){
        int t=n>>(i*3)&0b111;
        if(t){
            int c=(f>>(i*2)&0b11)+(f>>(i*2+2)&0b11);
            t=((t-1+c)&0b11)+1;
        }
        r|=t<<(i*3);
    }
    return r;
}

int solve(vi const& v){
    mii prev,next;
    prev[v[0]]=eval(v[0]);
    rep(i,4){
        next.clear();
        each(e,prev){
            int bef=eval(e.first);
            rep(f,1<<8){
                int x=flip(e.first,f),y=flip(v[i+1],f);
                int t=e.second-bef+eval(x)+eval(y);
                next[y]=max(next[y],t);
            }
        }
        swap(prev,next);
    }
    int ans=0;
    each(e,prev)ans=max(e.second,ans);
    return ans;
}

int main(){
    int n;cin>>n;
    rep(x,n){
        vi v(5);
        rep(i,5)rep(j,5){
            int t;cin>>t;
            v[i]<<=3;
            v[i]|=t;
        }
        cout<<solve(v)<<endl;
    }
}