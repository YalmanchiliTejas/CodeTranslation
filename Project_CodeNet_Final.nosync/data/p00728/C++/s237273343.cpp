#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> score;

int main()
{
    int n;
    while(cin >> n && n) {
        score.resize(n);
        for(int i = 0; i < n; i++) 
            cin >> score[i];

        sort(score.begin(), score.end());
        int sum = 0;
        for(int i = 1; i < n - 1; i++) 
            sum += score[i];
             
        cout << sum / (n - 2) << endl;
           
    }
}