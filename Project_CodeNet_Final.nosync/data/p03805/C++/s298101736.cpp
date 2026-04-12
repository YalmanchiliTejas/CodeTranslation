#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A[8][8] = {};
int main(){
    int N,M,a,b;
    int ans = 0;
    bool flag;
    vector<int> list;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        A[a-1][b-1] = 1;
        A[b-1][a-1] = 1;
    }
    for(int i=1;i<N;i++) list.push_back(i);
    do{
        flag = true;
        if(A[0][list[0]] == 0) continue;
        for(int i=0;i<N-2;i++){
            if(A[list[i]][list[i+1]] == 0){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(list.begin(),list.end()));
    cout << ans << endl;
    return 0;
}
