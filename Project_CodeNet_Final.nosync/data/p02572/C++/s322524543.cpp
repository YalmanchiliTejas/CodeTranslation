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
#define YN(X) ((X)? "Yes" : "No")
#define SWAP(T, X, Y) {T t; t = X; X = Y; Y = t;}

#define F first
#define S second
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
    const unsigned long long mod = 1E9+7;
    int N;
    cin >> N;
    unsigned long long A[N];
    unsigned long long sum = 0, out = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        out += sum*A[i];
        out %= mod;
        sum += A[i];
        sum %= mod;
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
    for(t = 1; t <= T; t++)
    {
        TC(t);
    }
    return 0;
}
