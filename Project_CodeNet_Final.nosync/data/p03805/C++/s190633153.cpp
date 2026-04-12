#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> node(N);
    for(int i = 0;i < N;i++){
        node.at(i) = i + 1;
    }

    vector<pair<int,int>> edge(M);
    int a,b;
    for(int i = 0;i < M;i++){
        cin >> a >> b;
        edge.at(i) = pair<int,int>(a,b);
    }

    bool can = false;
    bool can_can = false;
    int count = 0;
    do{
        can = true;
        for(int i = 0;i < N - 1;i++){
            can_can = false;
            pair<int,int> p(min(node.at(i),node.at(i+1)),max(node.at(i),node.at(i+1)));
            for(auto q : edge){
                if(p == q){
                    can_can = true;
                    break;
                }
            }
            if(!can_can){
                can = false;
                break;
            }
        }
        if(can){
            count++;
        }
    }while(next_permutation(node.begin()+1,node.end()));

    cout << count << endl;
}