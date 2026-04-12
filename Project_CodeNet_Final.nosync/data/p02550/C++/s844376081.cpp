// Library
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// TYPEDEFS
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

// CONSTANTS
#define SZA 0
#define SZB 0

// MACRO
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
#define ABS(X) (((X) > 0)? (X) : -(X))
#define YN(X) ((X)? "YES" : "NO")
#define SWAP(T, X, Y) {T t; t = X; X = Y; Y = t;}

#define F1 first
#define S2 second
#define PB push_back
#define MP make_pair


// Global Tables

//ull gPreProcess[SZA][SZB];

// Functions

void Print2DVector(vector<vector<int>>& v)
{
    ull i, j; 
    for(i = 0; i < v.size(); i++)
    {
        for(j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
            if(j == v[i].size()-1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}

void PrintVector(vi& v)
{
    ull i;
    for(i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if(i == v.size()-1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

void PrintArr(int* a, ull N)
{
    ull i;
    for(i = 0; i < N; i++)
    {
        cout << a[i];
        if(i == N-1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

void PreProcessTables()
{
    ull i, j;
    for(i = 0; i < SZA; i++)
    {
        for(j = 0; j < SZB; j++)
        {
            break;
        }
        break;
    }
}

void TC(int t)
{
    ull N, X, M, val, a, b, f, l, out = 0;
    vector<ull> cycle;
    cin >> N >> X >> M;
    if(N < M)
    {
        while(N > 0 && X > 0)
        {
            out += X;
            X *= X;
            X = X - ((X/M)*M);
            N--;
        }
    }
    else
    {
        val = 2*M;
        while(val > 0)
        {
            cycle.PB(X);
            X *= X;
            X = X - ((X/M)*M);
            val--;
        }
        a = 1, b = 2;
        while(cycle[a] != cycle[b])
        {
            a++;
            b += 2;
        }
        a = 0;
        while(cycle[a] != cycle[b])
        {
            a++;
            b++;
        }
        f = a;
        b = a+1;
        l = 1;
        while(cycle[a] != cycle[b])
        {
            b++;
            l++;
        }
        for(ull i = 0; i < f; i++)
        {
            out += cycle[i];
        }
        a = (N-f)/l;
        b = (N-f)%l;
        for(ull i = f; i < f+l; i++)
        {
            out += a*cycle[i];
        }
        for(ull i = f; i < f+b; i++)
        {
            out += cycle[i];
        }
    }
    cout << out << endl;
}

// Main

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    PreProcessTables();

    int T = 1, t;
    //cin >> T;
    for(t = 1; t <= T; t++)
    {
        TC(t);
    }
    return 0;
}
