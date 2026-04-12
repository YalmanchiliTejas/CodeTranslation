#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    bool first = true;

    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<pair<pair<int, int>, string> > score(n);
        for(int i=0; i<n; ++i){
            int a, b, c;
            cin >> score[i].second >> a >> b >> c;
            score[i].first.first = 3 * a + c;
            score[i].first.second = n-i;
        }

        sort(score.rbegin(), score.rend());
        if(first)
            first = false;
        else
            cout << endl;
        for(int i=0; i<n; ++i){
            cout << score[i].second << ',' << score[i].first.first << endl;
        }
    }
}