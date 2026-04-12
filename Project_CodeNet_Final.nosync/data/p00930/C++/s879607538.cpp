#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


//0-index
template<typename T,typename U> //T::要素,U::作用素
class late_seg_tree{
private:
    typedef pair<T,U> node;
    vector<vector<node>> tree;
    ll high;
    T err_T;
    U err_U;
    ll err;
    
    T F(T,T); //要素のマージ (要素,要素)
    T G(T,U,ll); //作用素->要素 (要素,作用素,場所)
    U H(U,U); //作用素のマージ (作用素,作用素)
    T I(T,U,ll,ll); //作用素->区間要素 (要素,作用素,l,r) [l,r)
    
    ll bit_size(ll a){
        for(int i=1;i<63;i++){
            if(1<<i >= a){return i;}
        }
        return err;
    }
    
    //[l,r)
    void update(ll h,ll where,ll l,ll r,U u){
        ll L=where<<(high-h-1);
        ll R=(where+1)<<(high-h-1);
        if(r<=L || R<=l){return;}
        if(h==high-1){tree[h][where].F=G(tree[h][where].F,u,where); return;}
        if(l<=L && R<=r){
            tree[h][where].S=H(tree[h][where].S,u);
            tree[h][where].F=F(tree[h+1][where*2].F,tree[h+1][where*2+1].F);
            tree[h][where].F=I(tree[h][where].F,tree[h][where].S,L,R);
        }
        else{
            update(h+1,where*2,l,r,u);
            update(h+1,where*2+1,l,r,u);
            tree[h][where].F=F(tree[h+1][where*2].F,tree[h+1][where*2+1].F);
            tree[h][where].F=I(tree[h][where].F,tree[h][where].S,L,R);
        }
    }
    
    T search(ll h,ll where,ll l,ll r){
        ll L=where<<(high-h-1);
        ll R=(where+1)<<(high-h-1);
        if(r<=L || R<=l){return err_T;}
        if(h==high-1){return tree[h][where].F;}
        if(l<=L && R<=r){return tree[h][where].F;}
        else{
            update(h+1,where*2,L,R,tree[h][where].S);
            update(h+1,where*2+1,L,R,tree[h][where].S);
            tree[h][where].S=err_U;
            T ret=err_T;
            ret=F(ret,search(h+1,where*2,l,r));
            ret=F(ret,search(h+1,where*2+1,l,r));
            return ret;
        }
        return err_T;
    }
    
public:
    late_seg_tree(ull size,T err_T,U err_U):err_T(err_T),err_U(err_U){
        err=1e18+7;
        high=bit_size(size)+1;
        tree.resize(high);
        for(int i=0;i<high;i++){
            tree[i].resize(1<<i,{err_T,err_U});
        }
    }
    
    late_seg_tree(vector<T> t,T err_T,U err_U):err_T(err_T),err_U(err_U){
        err=1e18+7;
        high=bit_size(t.size())+1;
        tree.resize(high);
        for(int i=0;i<high;i++){
            tree[i].resize(1<<i,{err_T,err_U});
        }
        for(int i=0;i<t.size();i++){
            tree[high-1][i]={t[i],err_U};
        }
        for(ll h=high-2;h>=0;h--){
            for(int i=0;i<tree[h].size();i++){
                tree[h][i].F=F(tree[h+1][i*2].F,tree[h+1][i*2+1].F);
            }
        }
    }
    
    void update(ll l,ll r,U u){
        update(0,0,l,r,u);
    }
    
    T search(ll l,ll r){
        return search(0,0,l,r);
    }
};




int main(){
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<pll> S(n,{E,E});
    vector<bool> str(n,false);
    for(int i=0;i<n;i++){
        if(s[i]==')'){S[i].F=i;}
    }
    for(int i=0;i<n;i++){
        str[i]= s[i]=='(';
        S[i].S= s[i]=='('?1:-1;
        if(i!=0){S[i].S+=S[i-1].S;}
    }
    late_seg_tree<pll,pair<bool,ll>> tree(S,{E,E},{false,0});
    while(q--){
        ll x;
        cin>>x;
        x--;
        if(str[x]){
            tree.update(x,x+1,{true,0});
            pll w=tree.search(0,x+1);
            cout<<w.F+1<<endl;
            tree.update(w.F,w.F+1,{true,0});
            if(w.F!=x){
                tree.update(w.F,x,{false,2});
            }
            str[x]=!str[x];
            str[w.F]=!str[w.F];
        }
        else{
            if(x==0){cout<<1<<endl; continue;}
            ll l=0,r=x-1;
            while(r-l>3){
                ll m=l+(r-l)/2;
                if(tree.search(m,x).S>=2){r=m;}
                else{l=m+1;}
            }
            bool done=false;
            for(ll i=l;i<=r && !done;i++){
                if(tree.search(i,x).S>=2){
                    cout<<i+1<<endl;
                    str[i]=!str[i];
                    str[x]=!str[x];
                    tree.update(x,x+1,{true,0});
                    tree.update(i,i+1,{true,0});
                    tree.update(i,x,{false,-2});
                    done=true;
                }
            }
            if(!done){
                cout<<x+1<<endl; continue;
            }
        }
    }
    
    
    
    return 0;
}


template<typename T,typename U>
T late_seg_tree<T,U>::F(T a,T b){
    return {min(a.F,b.F),min(a.S,b.S)};
}

template<typename T,typename U>
T late_seg_tree<T,U>::G(T a,U b,ll where){
    if(b.F){
        if(a.F==E){a.F=where;}
        else{a.F=E;}
    }
    a.S+=b.S;
    return a;
}

template<typename T,typename U>
U late_seg_tree<T,U>::H(U a,U b){
    a.F|=b.F;
    a.S+=b.S;
    return a;
}

template<typename T,typename U>
T late_seg_tree<T,U>::I(T a,U b,ll l,ll r){
    a.S+=b.S;
    return a;
}

