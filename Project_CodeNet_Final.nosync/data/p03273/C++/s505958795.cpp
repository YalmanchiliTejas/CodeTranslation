#include <iostream>
#include <string>
using namespace std;

string mat[110];
bool erase_i[110], erase_j[110];

int main()
{
    int n, m;

    cin >> n >> m;
    
    for(int i = 0; i < n; i ++) cin >> mat[i];
    
    for(int i = 0; i < n; i ++)
    {
        erase_i[i] = true;
        for(int j = 0; j < m; j ++)
            if(mat[i][j] == '#')
            {
                erase_i[i] = false;
                break;
            }
    }
    for(int j = 0; j < m; j ++)
    {
        erase_j[j] = true;
        for(int i = 0; i < n; i ++)
            if(mat[i][j] == '#')
            {
                erase_j[j] = false;
                break;
            }
    }
    //cout << "aaa" << endl;

    for(int i = 0; i < n; i ++)
    {
        if(erase_i[i]) continue;
        
        for(int j = 0; j < m; j ++)
            if(!erase_j[j])
                cout << mat[i][j];
        cout << endl;
    }
    return 0;
}