#include <iostream>
#include <string>
using namespace std;

typedef long long lint;

int main(){
    int N;
    string s;
    cin >> N >> s;
    string init[4]={"SS","SW","WS","WW"};

    for(int i=0;i<4;i++){
        char *res;
        res=new char[N];
        res[0]=init[i][0];
        res[1]=init[i][1];

        for(int j=1;j<N-1;j++){
            if((s[j]=='o' && res[j]=='S')||(s[j]=='x' && res[j]=='W')) res[j+1]=res[j-1];
            else res[j+1]=(res[j-1]=='S'?'W':'S');
        }
        char test[2];

        if((s[N-1]=='o' && res[N-1]=='S')||(s[N-1]=='x' && res[N-1]=='W')) test[0]=res[N-2];
        else test[0]=(res[N-2]=='S'?'W':'S');
        if((s[0]=='o' && res[0]=='S')||(s[0]=='x' && res[0]=='W')) test[1]=res[N-1];
        else test[1]=(res[N-1]=='S'?'W':'S');

        if(test[0]==init[i][0] && test[1]==init[i][1]){
            for(int i=0;i<N;i++) cout << res[i];
            cout << endl;
            return 0;
        }
        delete[] res;
    }
    cout << (-1) << endl;
    return 0;
}