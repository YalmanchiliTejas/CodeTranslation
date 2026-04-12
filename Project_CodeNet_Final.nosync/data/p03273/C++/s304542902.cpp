#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++)
    {
        cin >> a[i];
    }
    
    int delH[H] = {};
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (a.at(i)[j] == '#')
            {
                //cout << "黒だ！";
                break;
            }
            //cout << "白だ！";
            delH[i] += 1;
        }   
        // cout << '\n';
    }

    /* for (int i = 0; i < H; i++)
    {
        cout << delH[i] << endl;
    } */
    
    int delW[W] = {};
    for (int j = 0; j < W; j++)
    {
        for (int i = 0; i < H; i++)
        {
            if (a.at(i)[j] == '#')
            {
                //cout << "黒だ！";
                break;
            }
            //cout << "白だ！";
            delW[j] += 1;
        }   
        // cout << '\n';
    }

    /* for (int j = 0; j < W; j++)
    {
        cout << delW[j] << endl;
    } */
    

    for (int i = 0; i < H; i++)
    {
        if(delH[i] == W) continue;

        for (int j = 0; j < W; j++)
        {
            if (delW[j] != H)
            {
                cout << a.at(i)[j];
            }

        }
        cout << '\n';
    }
    
    return 0;

}
