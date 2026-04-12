#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M), order(N);

    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < N; i++)
    {
        order[i] = i+1;
    }
    
    
    bool ok;
    int cnt = 0;
    do
    {
        for (int i = 0; i < N-1; i++)
        {
            for (int j = 0; j < M; j++)
            {
                ok = false;
                if(order[i] == a[j] && order[i+1] == b[j]){
                    ok = true;
                    break;
                }
                else if(order[i] == b[j] && order[i+1] == a[j]){
                    ok = true;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) cnt++;
    } while (next_permutation(order.begin()+1, order.end()));

    cout << cnt << endl;
}