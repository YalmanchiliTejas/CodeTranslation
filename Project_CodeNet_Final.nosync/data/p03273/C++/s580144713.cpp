#include<iostream>
#include<vector>
using namespace std;

int h, w;

int main(){
    cin >> h >> w;
    vector< vector<char> > m(h, vector<char>(w, 'a'));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        bool f = true;
        for (int j = 0; j < w; j++)
        {
            if(m[i][j] == '#'){
                f = false;
                break;
            }
        }
        if(f){
            for (int j = 0; j < w; j++)
            {
                m[i][j] = 'a';
            }
        }
    }
    for (int i = 0; i < w; i++)
    {
        bool f = true;
        for (int j = 0; j < h; j++)
        {
            if (m[j][i] == '#')
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            for (int j = 0; j < h; j++)
            {
                m[j][i] = 'a';
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        bool f = false;
        for (int j = 0; j < w; j++)
        {
            if(m[i][j] != 'a'){
                cout << m[i][j];
                f = true;
            }
        }
        if(f) cout << endl;
    }
    return 0;
}