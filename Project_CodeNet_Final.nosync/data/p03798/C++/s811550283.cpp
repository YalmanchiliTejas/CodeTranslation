#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef long long LL;

std::string getS(bool b[], int size);

using namespace std;
int main()
{
#ifdef LOCAL
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    string S;
    cin >> N;
    cin >> S;
    
    vector<pair<bool ,bool>> p = {{true, true},{true,false},{false,true},{false,false}};
    for(auto iter:p){
        bool a[N];
        a[0] = iter.first;
        a[1] = iter.second;

        for(int i=2;i<N;i++){
            if(a[i-1]){
                if(S[i-1] == 'o')a[i] = a[i-2];
                else a[i] = !a[i-2];
            }
            else{
                if(S[i-1] == 'o')a[i] = !a[i-2];
                else a[i] = a[i-2];
            }
        }

        bool isRight = true;
        for(int i=1;i<N+1;i++){
            if(a[i%N]){
                if((S[i%N] == 'o') != (a[(i-1)%N] == a[(i+1)%N])){
                    isRight = false;
                }
            }
            else{
                if((S[i%N] == 'o') != (a[(i-1)%N] != a[(i+1)%N])){
                    isRight = false;
                }
            }
        }
        if(isRight){
            cout << getS(a, N) << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
string getS(bool b[], int size){
    string s;
    for(int i=0;i<size;i++){
        if(b[i])s += "S";
        else s += "W";
    }
    return s;
}