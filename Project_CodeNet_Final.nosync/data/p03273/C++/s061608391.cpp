#include<bits/stdc++.h>
using namespace std;

vector<vector<char> > v;
void removeRow(int x)
{
    vector<vector<char> > ret;
    for(int i = 0; i < v.size(); i++)
    {
        if(i == x)
            continue;
        ret.push_back(vector<char>());
        for(int j = 0; j < v[i].size(); j++)
        {
            ret[ret.size() - 1].push_back(v[i][j]);
        }
    }
    v = ret;
}

void removeCol(int x)
{
    vector<vector<char> > ret;
    for(int i = 0; i < v.size(); i++)
    {
        ret.push_back(vector<char>());
        for(int j = 0; j < v[i].size(); j++)
        {
            if(j == x)
                continue;
            ret[ret.size() - 1].push_back(v[i][j]);
        }
    }
    v = ret;
}

bool isRowWhite(int x)
{
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != '.')
        return 0;
    return 1;
}

bool isColWhite(int x)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i][x] != '.')
            return 0;
    return 1;
}

int w, h;

void disp()
{
    cout << "---------------------";
    for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    cout << "---------------------";
}

int main()
{
    while(cin >> h >> w)
    {
        v.clear();
        v.resize(h);
        for(int i = 0; i < h; i++)
        {
            v[i].resize(w);
            for(int j= 0; j < w; j++)
                cin >> v[i][j];
        }

        for(int i = 0; i < v.size(); i++)
        {
            if(isRowWhite(i))
            {
                removeRow(i);
                i--;
                //cout << "Row " <<i <<endl;
                //disp();
            }

        }

        for(int i = 0; i < v[0].size(); i++)
        {
            if(isColWhite(i))
            {
                removeCol(i);
                i--;
                //cout << "Col " <<i <<endl;
                //disp();
            }
        }

        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
