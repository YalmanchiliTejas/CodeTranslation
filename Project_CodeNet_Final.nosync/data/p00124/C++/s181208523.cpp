#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

bool compare(const pair<int, int> &p, const pair<int, int> &q) 
{
    return (p.first != q.first) ? p.first > q.first : p.second < q.second;
}

int main()
{
    bool nl = false;
    int n;

    while (cin >> n) {
        if (!n)
            break;
        if (nl)
            cout << endl;

        vector< pair<int, int> > tourn;
        vector<string> name;

        for (int i = 0; i < n; i++) {
            int win, los, ev;
            string str;
        
            cin >> str >> win >> los >> ev;

            tourn.push_back(pair<int, int>(win * 3 + ev, i));
            name.push_back(str);
        }
        sort(tourn.begin(), tourn.end(), compare);
        
        for (int i = 0; i < tourn.size(); i++)
            cout << name[tourn[i].second] << ',' << tourn[i].first << endl;
        nl = true;
    }

    return 0;
}