#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    ll N,M;
    cin >> N >> M;
    vector<int> array(N); //順列の一覧
    vector<vector<int>> pass(M,vector<int>(2));
    rep(i,N){
        array.at(i) = i+1;
    }
    rep(i,M){
        cin >> pass.at(i).at(0) >> pass.at(i).at(1);
    }
    int counter = 0;
    ll length = 0;
    bool finished = false,reach = false;
    do{
        if(array.at(0)!=1){
            break;
        }
        reach = false;
        rep(i,N-1){//arrayを最後まで見る
            finished = true;
            rep(j,M){ //passの中にarray.at(i)とarray.at(i+1)を繋ぐものがあるか
                if(pass.at(j).at(0)==min(array.at(i),array.at(i+1)) 
                && pass.at(j).at(1)==max(array.at(i),array.at(i+1)) ){
                    finished = false;
                    break;//あったらOKでまだ探索、finishedをfalseにしてbreak;
                }
            }
            if(finished){
                break;//見つからなかった場合
            }
            if(i==N-2){
                reach = true;
            }
        }
        if(reach){
            counter++;
        }
    }while(next_permutation(array.begin(),array.end()));
    cout << counter << endl; 
    return 0;
}
