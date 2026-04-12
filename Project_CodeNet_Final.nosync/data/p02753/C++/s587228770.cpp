#include<iostream>
#include<string>
#include<stack>/*** LIFO *** stack<type> var;
push(), top():to get data, pop():to remove, size(), empty() ***/
using namespace std;

#define Fp(I, STAT, END) for(int I = STAT; I < END; I++)
#define Fm(I, STAT, END) for(int I = STAT; I > END; I--)

int main(){
    string S;
    cin >> S;
    if(S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}
