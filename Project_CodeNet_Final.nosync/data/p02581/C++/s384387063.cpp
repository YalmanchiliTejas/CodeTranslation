#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int solve(int N, vector<int> A)
{
    vector<vector<int>> T(N, vector<int>(N, -N));
    T[A[0]][A[1]] = 0;

    int M = 0;  // M = max(T)
    vector<int> M1(N, -N);  // M1[x] = max(T[i][x])
    vector<int> M2(N, -N);  // M2[x] = max(T[x][i])
    M1[A[1]] = 0;
    M2[A[0]] = 0;

    int base = 0;

    for (int i=2; i+2<3*N; i+=3)
    {
        sort(A.begin()+i, A.begin()+i+3);

        if (A[i]==A[i+1] && A[i]==A[i+2])
        {
            base++;
            continue;
        }

        vector<pair<pair<int, int>, int>> U;

        if (A[i]==A[i+1] || A[i+1]==A[i+2])
        {
            int a = A[i+1];
            int r = a==A[i] ? A[i+2] : A[i];
            for (int j=0; j<N; j++)
                U.push_back({{j, r}, max(T[j][a]+1, T[a][j]+1)});
        }

        U.push_back({{A[i], A[i+1]}, T[A[i+2]][A[i+2]]+1});
        U.push_back({{A[i], A[i+2]}, T[A[i+1]][A[i+1]]+1});
        U.push_back({{A[i+1], A[i+2]}, T[A[i]][A[i]]+1});

        U.push_back({{A[i], A[i+1]}, M});
        U.push_back({{A[i], A[i+2]}, M});
        U.push_back({{A[i+1], A[i+2]}, M});

        for (int j=0; j<N; j++)
        {
            U.push_back({{A[i], j}, max(M1[j], M2[j])});
            U.push_back({{A[i+1], j}, max(M1[j], M2[j])});
            U.push_back({{A[i+2], j}, max(M1[j], M2[j])});
        }

        for (auto u: U)
        {
            int x = u.first.first;
            int y = u.first.second;
            int v = u.second;
            T[x][y] = max(T[x][y], v);
            M = max(M, v);
            M1[y] = max(M1[y], v);
            M2[x] = max(M2[x], v);
        }

        //for (int x=0; x<N; x++)
        //{
        //    for (int y=0; y<N; y++)
        //        cout<<" "<<T[x][y];
        //    cout<<endl;
        //}
        //cout<<endl;
    }

    int ans = 0;
    for (int x=0; x<N; x++)
        for (int y=0; y<N; y++)
            ans = max(ans, T[x][y]+base+(x==y && x==A[3*N-1] ? 1 : 0));
    return ans;
}

int naive(int N, vector<int> A)
{
    vector<vector<int>> T(N, vector<int>(N, -N));
    T[A[0]][A[1]] = 0;
    T[A[1]][A[0]] = 0;

    for (int i=2; i+2<3*N; i+=3)
    {
        vector<vector<int>> P(N, vector<int>(N, -N));
        P.swap(T);

        for (int x=0; x<N; x++)
        for (int y=0; y<N; y++)
        {
            vector<int> V = {A[i], A[i+1], A[i+2], x, y};
            sort(V.begin(), V.end());

            do
            {
                int a = V[0]==V[1] && V[1]==V[2] ? 1 : 0;
                T[V[3]][V[4]] = max(T[V[3]][V[4]], P[x][y]+a);
            }
            while(next_permutation(V.begin(), V.end()));
        }
    }

    int ans = 0;
    for (int x=0; x<N; x++)
    for (int y=0; y<N; y++)
        ans = max(ans, T[x][y]+(x==y && y==A[3*N-1] ? 1 : 0));
    return ans;
}

int main()
{
    //while (true)
    //{
    //    int N = 10;
    //    vector<int> A(3*N);
    //    for (int &a: A)
    //        a = rand()%N;

    //    int a1 = solve(N, A);
    //    int a2 = naive(N, A);
    //    if (a1!=a2)
    //    {
    //        cout<<N<<endl;
    //        for (int a: A)
    //            cout<<" "<<a+1;
    //        cout<<endl;
    //        cout<<a1<<endl;
    //        cout<<a2<<endl;
    //        break;
    //    }
    //}

    int N;
    cin>>N;
    vector<int> A(3*N);
    for (int &a: A)
        cin>>a, a--;

    int ans = solve(N, A);
    
    cout<<ans<<endl;
}
