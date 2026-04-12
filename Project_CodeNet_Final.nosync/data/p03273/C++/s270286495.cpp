#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    vector<string> a(N);
    vector<bool> row(N, false);
    vector<bool> col(W, false);
    for (int i = 0; i < N;i++){
        cin >> a[i];
    }

    for (int i = 0; i < N;i++){
        for (int j = 0; j < W;j++){
            if(a[i][j]=='#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

        for (int i = 0; i < N; i++)
        {
            if (row[i])
            {
                for (int j = 0; j < W; j++)
                {
                    if (col[j])
                    {
                        cout << a[i][j];
                    }
                }
                cout << endl;
            }
        }
}