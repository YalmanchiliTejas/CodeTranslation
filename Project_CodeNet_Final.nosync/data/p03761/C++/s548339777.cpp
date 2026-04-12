//http://abc058.contest.atcoder.jp/tasks/arc071_a
#include <iostream>
using namespace std;
 
int n = 0;
string S[50] = {};
 
void readInput(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
}
 
int main(void){
    readInput();
    int count[50][26] = {};
    const int a = int('a');
    for(int i=0; i<n; i++){
        int size = S[i].size();
        for(int j=0; j<size; j++){
            int c = int(S[i][j])-a;
            count[i][c]++;
        }
    }
    int min;
    for(int i=0; i<26; i++){
        min = 100;
        for(int j=0; j<n; j++){
            if(min > count[j][i]){
                min = count[j][i];
            }
        }
        for(int j=0; j<min; j++){
            cout << char(i+a);
        }
    }
    cout << endl;
    return 0;
}
