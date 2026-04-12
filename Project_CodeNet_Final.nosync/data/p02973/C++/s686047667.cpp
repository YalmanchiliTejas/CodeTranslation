#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N; cin>>N;
    vec_int A(N);
    rep(i,N)cin>>A.at(i);

    multiset<int> numset;

    map<int, int> numcount;

    rep(i,N){
        auto pos = numset.lower_bound(A.at(i));
        
        if(pos==numset.begin()){
            numset.insert(A.at(i));
            numcount[A.at(i)]++;
        }else{
            --pos;
            numcount[*pos]--;
            if(numcount[*pos]<1){
                numset.erase(*pos);
            }

            numset.insert(A.at(i));
            numcount[A.at(i)]++;
        }
    }
    int count=0;
    for(auto temp: numcount){
        count+=temp.second;

    }
    cout<<count<<endl;




    return 0;
}