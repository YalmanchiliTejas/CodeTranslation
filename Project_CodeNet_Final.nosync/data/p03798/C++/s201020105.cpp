#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define reprs(i, s, e) for(int i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int animal[n];
    string answer;
    cin >> answer;

    bool exist1 = false;
    bool exist2 = false;
    rep(i1, 2){
        rep(i2, 2){
            exist1 = false;
            exist2 = false;

            fill(animal, animal+n, 0);

            animal[0] = 2*i1 - 1;
            animal[1] = 2*i2 - 1;

            if(animal[0] == 1){
                if(answer[0] == 'o'){
                    animal[n-1] =  animal[1];
                }
                else{
                    animal[n-1] = -animal[1];
                }
            }
            else{
                if(answer[0] == 'o'){
                    animal[n-1] = -animal[1];
                }
                else{
                    animal[n-1] =  animal[1];
                }
            }

            reps(i, 2, n-1){

                if(animal[i-1] == 1){
                    if(answer[i-1] == 'o'){
                        animal[i] =  animal[i-2];
                    }
                    else{
                        animal[i] = -animal[i-2];
                    }
                }
                else{
                    if(answer[i-1] == 'o'){
                        animal[i] = -animal[i-2];
                    }
                    else{
                        animal[i] =  animal[i-2];
                    }
                }

                // cout << animal[i] << endl;
            }

            if(animal[n-2] == 1){
                if(answer[n-2] == 'o'){
                    if(animal[n-1] == animal[n-3]){
                        exist1 = true;
                    }
                }
                else{
                    if(animal[n-1] == -animal[n-3]){
                        exist1 = true;
                    }
                }
            }
            else{
                if(answer[n-2] == 'o'){
                    if(animal[n-1] == -animal[n-3]){
                        exist1 = true;
                    }
                }
                else{
                    if(animal[n-1] == animal[n-3]){
                        exist1 = true;
                    }
                }
            }

            if(animal[n-1] == 1){
                if(answer[n-1] == 'o'){
                    if(animal[0] == animal[n-2]){
                        exist2 = true;
                    }
                }
                else{
                    if(animal[0] == -animal[n-2]){
                        exist2 = true;
                    }
                }
            }
            else{
                if(answer[n-1] == 'o'){
                    if(animal[0] == -animal[n-2]){
                        exist2 = true;
                    }
                }
                else{
                    if(animal[0] == animal[n-2]){
                        exist2 = true;
                    }
                }
            }

            if(exist1 && exist2) break;
        }

        if(exist1 && exist2) break;
    }

    if(exist1 && exist2){
        rep(i, n){
            if(animal[i] == 1){
                cout << 'S';
            }
            else{
                cout << 'W';
            }
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}