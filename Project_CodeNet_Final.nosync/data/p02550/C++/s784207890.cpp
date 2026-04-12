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

int nextVal(int N, int M){
//    cout<<N<<" "<<M<<endl;
    return (N*N)%M;
}

signed main(){
    int N, X, M; cin>>N>>X>>M;

    // 絶対に周期性があり、その周期は10^5以下
    vec_int exist(M+1,-1);

    int a_val = X;
    int index=1;
    exist.at(a_val) = index;

    int cycle;
    int start_pos;
    int cycle_start_num;
    while(true){
        a_val = nextVal(a_val, M);
        index++;
 //       cout<<index<<" "<<a_val<<" "<<M<<" "<<exist.at(a_val)<<endl;
        if(exist.at(a_val)!=-1){
            start_pos = exist.at(a_val);
            cycle = index-start_pos;
            cycle_start_num = a_val;
            break;
        }
        exist.at(a_val)=index;
    }
//    cout<<X<< " "<<index<<endl;
//    cout<<cycle<< " "<<start_pos<<endl;

    int cycle_N = 0;
    a_val = cycle_start_num;
    cycle_N+=a_val;
    for(int i=1;i<cycle;i++){
        a_val = nextVal(a_val, M);
        cycle_N+=a_val;
    }
    /*
    a_val = X;
    index=1;
    while(true){
        a_val = nextVal(a_val, M);
        index++;
        if(index==start_pos)cycle_start_num = a_val;
        if(index>=start_pos && index<start_pos+cycle){
            cycle_N += a_val;
        }else if(index>=start_pos+cycle){
            break;
        }
    }
    */

    if(N<3*pow(10,7)){
        int tot_val = 0;
        int a = X;
        tot_val += a;
        for(int i=1;i<N;i++){
            a = nextVal(a,M);
            tot_val += a;
        }
        cout<<tot_val<<endl;
        return 0;
    }

    if(N<start_pos+cycle){
        int tot_val = 0;
        int a = X;
        tot_val += a;
        for(int i=1;i<N;i++){
            a = nextVal(a,M);
            tot_val += a;
        }
        cout<<tot_val<<endl;
        return 0;
    }else{
        ll tot_val = 0;
        // サイクルの数を数える
        int cycle_num = (N-(start_pos-1))/cycle;
        //int yobun = (N-(start_pos-1)) - cycle_num*cycle;
        int yobun = (N-(start_pos-1))%cycle;

        int a = X;
        if(start_pos>1){
        tot_val += a;
        for(int i=1;i<start_pos-1;i++){
            a = nextVal(a,M);
            tot_val += a;
        }
        }

        tot_val += cycle_num* cycle_N;

        if(yobun>0){
        a = cycle_start_num;
        tot_val += a;
        for(int i=1;i<yobun;i++){
            a = nextVal(a,M);
            tot_val += a;
        }
        }

        cout<<tot_val<<endl;
        return 0;
    }






    return 0;
}