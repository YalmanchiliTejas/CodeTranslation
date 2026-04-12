#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(){
        int n;
        cin >> n;
        while(n){
                int sq[n][n];
                memset(sq,0,sizeof(sq));
                int x[2] = {n/2,n/2+1};
                int m = 1;
                while(!sq[x[0]][x[1]]){
                        sq[x[0]][x[1]] = m;
                        m++;
                        for(int i = 0; i < 2; i++){
                                x[i]++;
                                x[i] %= n;
                        }   
                        if(sq[x[0]][x[1]]){
                                x[0] += n-1;
                                x[1]++;
                                x[0] %= n;
                                x[1] %= n;
                        }   
                }   
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                cout << setw(4) << sq[j][i];
                        }   
                        cout << endl;
                }   
                cin >> n;
        }   
}