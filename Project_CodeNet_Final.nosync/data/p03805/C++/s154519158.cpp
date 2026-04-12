#include <bits/stdc++.h>//ビットの一番右端は０番目
using namespace std;//https://atcoder.jp/contests/abc054/tasks/abc054_c
int main(void){
//    bit |= (1<<i);// i番目のビットを立てる
//    bit &= ~(1<<j);// j番目のビットを消す
//    if (bit & (1<<k)){// k番目のビットが立っているか？
//    if (!(bit & (1<<k))){// k番目のビットが消えているか？
//    cout << bitset<8>(bit) << endl;
    int N,M;
    cin >> N >> M;
    vector<pair<int, int> > paths;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        paths.push_back(make_pair(a,b));
    }
    
    stack<pair<int, int> >st;// キュー st を定義  <int , int> = < 位置pos 1～N , 状態state bitで表現 >
    st.push(make_pair(1,0));//スタート地点をstにプッシュ
    int count=0;
    while(st.empty()==false) {
        int pos=st.top().first;
        int state=st.top().second;
        st.pop(); // stackの一番上の要素を削除
        state |= (1<<(pos-1));// i番目(１以上）のビットを立てる
        for(int j=0;j<M;j++){
            int a=paths[j].first;
            int b=paths[j].second;
            if( (a==pos) && !(state & (1<<(b-1))) ){// b番目のビットが立っていないか？
                st.push(make_pair(b,state));//スタート地点をstにプッシュ
            }
            if( (b==pos) && !(state & (1<<(a-1))) ){// a番目のビットが立っていないか？
                st.push(make_pair(a,state));//スタート地点をstにプッシュ
            }
        }
        if(pow(2,N)-1==state){count++;}
    }
    cout << count << endl;
    return 0;
}

