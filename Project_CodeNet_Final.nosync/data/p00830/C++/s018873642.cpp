#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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

vector<int> parent;
vector<map<string, int> > child;
vector<bool> isFile;

void addFile(int curr, const string& s, int i)
{
    ++ i;
    if(i >= s.size()){
        isFile[curr] = true;
        return;
    }

    int j = s.find('/', i);
    if(j == string::npos)
        j = s.size();

    string t = s.substr(i, j-i);
    if(child[curr].find(t) == child[curr].end()){
        parent.push_back(curr);
        child.resize(child.size() + 1);
        child[curr][t] = child.size() - 1;
        isFile.push_back(false);
    }

    int next = child[curr][t];
    addFile(next, s, j);
}

int findFile(int curr, const string& s, int i)
{
    if(curr == -1)
        return -1;

    ++ i;
    if(i >= s.size()){
        if(isFile[curr] && i > s.size())
            return curr;
        else if(child[curr].find("index.html") != child[curr].end() && isFile[child[curr]["index.html"]])
            return child[curr]["index.html"];
        else
            return -1;
    }

    if(isFile[curr])
        return -1;

    int j = s.find('/', i);
    if(j == string::npos)
        j = s.size();

    string t = s.substr(i, j-i);
    if(t == ".")
        return findFile(curr, s, j);
    else if(t == "..")
        return findFile(parent[curr], s, j);
    else if(child[curr].find(t) != child[curr].end())
        return findFile(child[curr][t], s, j);
    else
        return -1;
}

int main()
{
    for(;;){
        int n, q;
        cin >> n >> q;
        if(n == 0)
            return 0;

        parent.assign(1, -1);
        child.assign(1, map<string, int>());
        isFile.assign(1, false);

        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            addFile(0, s, 0);
        }

        for(int i=0; i<q; ++i){
            string s, t;
            cin >> s >> t;

            int a = findFile(0, s, 0);
            int b = findFile(0, t, 0);

            if(a == -1 || b == -1)
                cout << "not found" << endl;
            else if(a == b)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}