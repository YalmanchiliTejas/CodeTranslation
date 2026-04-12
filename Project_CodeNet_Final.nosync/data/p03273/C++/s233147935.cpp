#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <class It> string join(It i1, It i2)
{
    ostringstream ss;
    for (auto it = i1; it != i2; ++it)
        ss << ((it == i1) ? "" : ", ") << (*it);
    return ss.str();
}

void Print() { cout << endl; }
template <class Head, class... Args> void Print(Head &&head, Args&&... args)
{
    cout << head;
    Print(args...);
}

#define Repeat(x, i, j) for (size_t x = i; x < j; ++x)

#ifdef DEBUG
#define Dump(x) cerr << #x << " = " << x << endl;
#define Dumps(x) cerr << #x << " : { " << join(x.begin(), x.end()) << " }" << endl;
#else
#define Dump(x)
#define Dumps(x)
#endif


using ull_t = unsigned long long;


int main()
{
    int H, W;
    cin >> H >> W;
    
    vector<vector<char>> M(H, vector<char>(W, '.'));
    vector<int> N1(H, 0), N2(W, 0);
    
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> M[i][j];
            if (M[i][j] == '#')
            {
                ++N1[i];
                ++N2[j];
            }
        }
    }

    for (int i = 0; i < H; ++i)
    {
        if (N1[i] == 0) continue;
        
        for (int j = 0; j < W; ++j)
        {
            if (N2[j] == 0) continue;

            cout << M[i][j];
        }
        cout << endl;
    }
}
