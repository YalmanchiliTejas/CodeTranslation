#include<bits/stdc++.h>
#define ALL(v) std::begin(v),std::end(v)
using lint=long long;
using ld=long double;
template<class T>using numr=std::numeric_limits<T>;
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint n;std::cin>>n;
    std::vector<lint>a(n);
    for(lint&x:a)std::cin>>x;
    lint sum=std::accumulate(ALL(a),0ll);
    for(lint X=std::max(0ll,sum-n*(n-1));X<=sum;X++){
        lint cnt=0;
        bool ng=false;
        for(lint x:a){
            x+=X;
            if(x%(n+1)==n){
                ng=true;
                break;
            }
            cnt+=x/(n+1);
        }
        if(ng)continue;
        if(cnt==X){
            std::cout<<X<<'\n';
            return 0;
        }
    }
}
