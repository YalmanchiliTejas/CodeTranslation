#include <iostream>
#include <string>
using namespace std;

char a[4][100005];
char s[100005];

    bool check(int x, int y, int z, int j){
        bool flag = false;
            if(s[y] == 'o'){
                if(a[j][y] == 'S'){
                    if(a[j][x] == 'S' && a[j][z] == 'S'){
                        flag = true;
                    }else if(a[j][x] == 'W' && a[j][z] == 'W'){
                        flag = true;
                    }
                }else if(a[j][y] == 'W'){
                    if(a[j][x] == 'S' && a[j][z] == 'W'){
                        flag = true;
                    }else if(a[j][x] == 'W' && a[j][z] == 'S'){
                        flag = true;
                    }
                }
            }else if(s[y] == 'x'){
                if(a[j][y] == 'S'){
                    if(a[j][x] == 'S' && a[j][z] == 'W'){
                        flag = true;
                    }else if(a[j][x] == 'W' && a[j][z] == 'S'){
                        flag = true;
                    }
                }else if(a[j][y] == 'W'){
                    if(a[j][x] == 'S' && a[j][z] == 'S'){
                        flag = true;
                    }else if(a[j][x] == 'W' && a[j][z] == 'W'){
                        flag = true;
                    }
                }
            }
            return flag;
    }
    
int main(void){
    long n;
    int cnt = 0;
    bool flag2 = false;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    a[0][0] = 'S';
    a[0][1] = 'S';
    
    a[1][0] = 'S';
    a[1][1] = 'W';
    
    a[2][0] = 'W';
    a[2][1] = 'S';
    
    a[3][0] = 'W';
    a[3][1] = 'W';

    for(int j=0;j<4;j++){
        for(int i=2;i<n;i++){
            if(a[j][i-2] == 'S'){
                if(a[j][i-1] == 'S'){
                    if(s[i-1] == 'o'){
                        a[j][i] = 'S';
                    }else if(s[i-1] == 'x'){
                        a[j][i] = 'W';
                    }
                }else if(a[j][i-1] == 'W'){
                    if(s[i-1] == 'o'){
                        a[j][i] = 'W';
                    }else if(s[i-1] == 'x'){
                        a[j][i] = 'S';
                    }
                }
            }else if(a[j][i-2] == 'W'){
                if(a[j][i-1] == 'S'){
                    if(s[i-1] == 'o'){
                        a[j][i] = 'W';
                    }else if(s[i-1] == 'x'){
                        a[j][i] = 'S';
                    }
                }else if(a[j][i-1] == 'W'){
                    if(s[i-1] == 'o'){
                        a[j][i] = 'S';
                    }else if(s[i-1] == 'x'){
                        a[j][i] = 'W';
                    }
                }
            }
        }
            if(check(n-3,n-2,n-1,j) == true && check(n-2,n-1,0,j) == true && check(n-1,0,1,j) == true){
                for(int i=0;i<n;i++){
                    cout << a[j][i];
                }
                cout << endl;
                return 0;
            }
    }
    
    cout << "-1" << endl;
    
    return 0;
}
