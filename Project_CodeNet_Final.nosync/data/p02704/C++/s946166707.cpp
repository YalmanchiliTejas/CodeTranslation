#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> S(N), T(N);
    for (int &s: S)
        cin>>s;
    for (int &t: T)
        cin>>t;
    vector<unsigned long long> U(N), V(N);
    for (unsigned long long &u: U)
        cin>>u;
    for (unsigned long long &v: V)
        cin>>v;

    vector<vector<unsigned long long>> A(N, vector<unsigned long long>(N));
    for (int d=0; d<64; d++)
    {
        int y00 = 0;
        int y01 = 0;
        int y10 = 0;
        int y11 = 0;
        for (int y=0; y<N; y++)
        {
            if (S[y]==0 && (U[y]>>d&1)==0)
                y00++;
            if (S[y]==0 && (U[y]>>d&1)==1)
                y01++;
            if (S[y]==1 && (U[y]>>d&1)==0)
                y10++;
            if (S[y]==1 && (U[y]>>d&1)==1)
                y11++;            
        }

        int x00 = 0;
        int x01 = 0;
        int x10 = 0;
        int x11 = 0;
        for (int x=0; x<N; x++)
        {
            if (T[x]==0 && (V[x]>>d&1)==0)
                x00++;
            if (T[x]==0 && (V[x]>>d&1)==1)
                x01++;
            if (T[x]==1 && (V[x]>>d&1)==0)
                x10++;
            if (T[x]==1 && (V[x]>>d&1)==1)
                x11++;
        }

        int cy = 0;
        bool f = true;
        for (int y=0; y<N; y++)
        {
            int cx = 0;
            for (int x=0; x<N; x++)
            {
                if (S[y]==0 && (U[y]>>d&1)==1 ||
                    T[x]==0 && (V[x]>>d&1)==1)
                {
                    A[y][x] |= 1ULL<<d;
                }
                else if (S[y]==1 && (U[y]>>d&1)==0 ||
                         T[x]==1 && (V[x]>>d&1)==0)
                    ;
                else
                {
                    if (y10==N-1 && y01==0)
                    {
                        if (T[x]==1 && (V[x]>>d&1)==1)
                            A[y][x] |= 1ULL<<d;
                        else
                        {
                            if (f && x11==0)
                                A[y][x] |= 1ULL<<d;
                            f = false;
                        }
                    }
                    else if (x10==N-1 && x01==0)
                    {
                        if (S[y]==1 && (U[y]>>d&1)==1)
                            A[y][x] |= 1ULL<<d;
                        else
                        {
                            if (f && y11==0)
                                A[y][x] |= 1ULL<<d;
                            f = false;
                        }
                    }
                    else if (y10==0 && y01==N-1)
                    {
                        if (T[x]==0 && (V[x]>>d&1)==0)
                            ;
                        else
                        {
                            if (!(f && x00==0))
                                A[y][x] |= 1ULL<<d;
                            f = false;
                        }
                    }
                    else if (x10==0 && x01==N-1)
                    {
                        if (S[y]==0 && (U[y]>>d&1)==0)
                            ;
                        else
                        {
                            if (!(f && y00==0))
                                A[y][x] |= 1ULL<<d;
                            f = false;
                        }
                    }
                    else
                    {
                        if ((cx+cy)%2!=0)
                            A[y][x] |= 1ULL<<d;
                    }
                }

                if (!(T[x]==0 && (V[x]>>d&1)==1) &&
                    !(T[x]==1 && (V[x]>>d&1)==0))
                    cx++;
            }

            if (!(S[y]==0 && (U[y]>>d&1)==1) &&
                !(S[y]==1 && (U[y]>>d&1)==0))
                cy++;
        }
    }

    bool ok = true;
    for (int y=0; y<N; y++)
    {
        unsigned long long t = A[y][0];
        for (int x=1; x<N; x++)
            if (S[y]==0)
                t &= A[y][x];
            else
                t |= A[y][x];
        if (t!=U[y])
            ok = false;
    }
    for (int x=0; x<N; x++)
    {
        unsigned long long t = A[0][x];
        for (int y=1; y<N; y++)
            if (T[x]==0)
                t &= A[y][x];
            else
                t |= A[y][x];
        if (t!=V[x])
            ok = false;
    }
    if (ok)
    {
        for (int y=0; y<N; y++)
        {
            for (int x=0; x<N; x++)
                cout<<(x==0 ? "" : " ")<<A[y][x];
            cout<<endl;
        }
    }
    else
        cout<<-1<<endl;
}
