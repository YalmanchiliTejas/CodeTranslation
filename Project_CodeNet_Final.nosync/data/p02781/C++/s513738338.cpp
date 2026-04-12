#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}

int main()
{
    string N;cin>>N;
    ll K=in();
    if(K>N.length()){cout<<0<<endl;return 0;}

    ll ans=0;
    for(ll digit=K;;++digit){
        if(digit<N.length()){
            ll d=1;
            for(int i=0;i<K-1;++i)d*=(digit-1-i);
            for(int i=1;i<=K-1;++i)d/=i;
            for(int i=0;i<K;++i)d*=9;
            ans+=d;
        }else{
            if(K==1){
                for(char i='1';i<='9';++i){
                    string foo=i+string(digit-1,'0');
                    if(foo<=N)++ans;
                }
            }else if(K==2){
                for(char i='1';i<='9';++i){
                    string foo=i+string(digit-1,'0');
                    for(int j=0;j<digit-1;++j){
                        for(char k='1';k<='9';++k){
                            string bar=foo;
                            bar[digit-1-j]=k;
                            if(bar<=N)++ans;
                        }
                    }
                }
            }else{
                for(char i='1';i<='9';++i){
                    string foo=i+string(digit-1,'0');
                    for(int j=0;j<digit-1;++j){
                        for(char k='1';k<='9';++k){
                            string bar=foo;
                            bar[digit-1-j]=k;
                            for(int l=j+1;l<digit-1;++l){
                                for(char m='1';m<='9';++m){
                                    string baz=bar;
                                    baz[digit-1-l]=m;
                                    if(baz<=N)++ans;
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
    }
    cout<<ans<<endl;
}
