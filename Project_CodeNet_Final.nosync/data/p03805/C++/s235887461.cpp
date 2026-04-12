#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<bool>> neighbor(N+1, vector<bool>(N+1, false));
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        neighbor.at(a).at(b) = true;
        neighbor.at(b).at(a) = true;
    }

    vector<int> perm(N);
    for(int i=0; i<N; i++)perm.at(i) = i+1;

    int res = 0;
    do{
        bool flag = true;
        for(int i=0; i<N-1; i++){
            int now = perm.at(i);
            int next = perm.at(i+1);
            if(!neighbor.at(now).at(next)){
                flag = false;
                break;
            }
        }
        if(flag)res++;
    }while(next_permutation(perm.begin()+1, perm.end()));

    cout << res << endl;
}