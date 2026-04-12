#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> graph(M);
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        pair<int, int> p;
        p = make_pair(a-1,b-1);
        graph.at(i) = p;
    }
    vector<int> visit_order(N);
    for(int i=0; i<N; i++){
        visit_order.at(i) = i;
    }
    int count=0;
    do{
        if(visit_order.at(0) != 0){
            break;
        }
        bool possible_order=true;
        for(int i=0; i<N-1;i++){
            bool possible_move=false;
            int begin=visit_order.at(i);
            int end=visit_order.at(i+1);
            for(int j=0; j<M; j++){
                if(graph.at(j).first==begin && graph.at(j).second==end){
                    possible_move = true;
                }
                if(graph.at(j).first==end && graph.at(j).second==begin){
                    possible_move =true;
                }
            }
            if (possible_move == false){
                possible_order = false;
            }
        }
        if(possible_order){
            count++;
        }
    }while(next_permutation(visit_order.begin(), visit_order.end()));
    cout << count <<endl;
}