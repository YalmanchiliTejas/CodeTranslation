#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,ans=0;
    cin >> N >> M;
    vector<int> v(2*M);//辺の格納
    for(int i=0;i < 2*M;i++){
        cin >> v.at(i);
    }
    vector<int> u(N);
    for(int i=0;i < N;i++){
        u.at(i) = i+1;
    }//昇順に頂点を格納
    
    do{
        int count=0;
        for(int i=0;i < N-1;i++){
            for(int j=0;j < 2*M-1;j+=2){
                if(u.at(i)==v.at(j) && u.at(i+1)==v.at(j+1)){
                    count++;
                }
                else if(u.at(i)==v.at(j+1) && u.at(i+1)==v.at(j)){
                    count++;
                }//頂点をつなぐ辺があるか
            }
        }
        if(count == N-1 && u.at(0)==1){
            ans++;
        }//すべての辺があったらその順列の進み方は可能
    }while(next_permutation(u.begin(),u.end()));
    cout << ans << endl;
}