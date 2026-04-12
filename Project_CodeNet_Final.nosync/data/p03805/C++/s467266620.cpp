#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<vector<int> > connect(N+1,vector<int>(N+1,0));

    for (int i=0; i<M; ++i)
    {
        int row,col;
        cin >> row >> col;
        connect[row][col] = connect[col][row] = 1;
        // cout << connect[row][col] << endl;
    }

    // for(int i=0; i<N; ++i)
    // {
    //     for (int j=0; i<N; ++j)
    //     {
    //         cout << connect[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << N << " " << M << endl;
    // for (int i=1; i<N+1; ++i)
    // {
    //     for (int j=1; j<N+1; ++j)
    //     {
    //         cout << connect[i][j] << " ";
    //     }
    //     cout << "" << endl;
    // }

    int cnt = 0;
    bool can = true;
    vector<int> v;
    for (int i=0; i<N-1; ++i)
    {
        v.push_back(i+2);
    }
    do {
        for (int i=0;i<v.size()-1;++i)
        {
            if( i==0 )
            {
                if(connect[1][v[i]] != 1)
                {
                    can = false;
                    break;
                }
            }

            if(connect[v[i]][v[i+1]] != 1)
            {
                can = false;
                break;
            }
        }
        if(can) ++cnt;
        can = true;
    } while (next_permutation(v.begin(), v.end()));


    // int pem = 0;
    // for (int bit=0; bit < (1<<N-1); ++bit)
    // {   
    //     vector<int> S;
    //     for (int i=0; i<N-1; ++i)
    //     {
    //         if(bit & (1<<i))
    //         {
    //             S.push_back(i);
    //         }
    //     }

    //     bool can = true;
    //     if (S.size() < N-1) continue; //すべての頂点を訪れているか
    //     for( int i=0; i<S.size(); ++i)
    //     {
    //         if(i==0)
    //         {
    //             if (connect[1][S[i]+2] != 1)
    //             {
    //                 can = false;
    //                 break;
    //             } 
    //         }
    //         else
    //         {
    //             if (connect[S[i-1]+2][S[i]+2] != 1)
    //             {
    //                 can = false;
    //                 break;
    //             } 
    //         }
    //     }

        // // bit の表す集合の出力
        // cout << bit << ": {";
        // for (int i = 0; i < (int)S.size(); ++i) {
        //     cout << S[i] << " ";
        // }
        // cout << "}" << endl;

        // if (can) ++pem;

    // }

    // for(int i=0; i<M; ++i)
    // {
    //     for (int j=0; i<M; ++j)
    //     {
    //         cout << connect[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << cnt << endl;
    return 0;
}