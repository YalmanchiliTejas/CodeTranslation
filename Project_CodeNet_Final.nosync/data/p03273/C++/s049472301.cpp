#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//for(int i = 0; i<n; i++)
 
 
int main()
{
    int h,w;cin>>h>>w;
    char a[100][100];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> a[i][j];
    }
    int c[100] = {0};
    for(int i = 0; i < h; i++){
        bool bo = false;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#') bo =  true;
        }
        if(bo) c[i]++;
    }
    int b[100] = {0};
    for(int i = 0; i < w; i++){
        bool bo = false;
        for(int j = 0; j < h; j++){
            if(a[j][i] == '#') bo =  true;
        }
        if(bo) b[i]++;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            if(c[i]&&b[j])cout << a[i][j];
        }
        if(c[i]) cout << endl;
    }
    return 0;
    
}