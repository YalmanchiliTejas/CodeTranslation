#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
#define umap unordered_map
const static ull INVALID_DIGIT = ~(ull)0;

int main()
{
    int N;
    cin >> N;
    vector<int> Hs(N);

    for (int i = 0; i < N; i++) {
        cin >> Hs[i];
    }

    int canSee = 1;
    int maxHeight = Hs[0];

    for (int i = 1; i < N; i++) {
        if (maxHeight <= Hs[i]) {
            canSee++;
        }
        maxHeight = std::max(maxHeight, Hs[i]);
    }

    cout << canSee << endl;

    return 0;
    return 0;
}