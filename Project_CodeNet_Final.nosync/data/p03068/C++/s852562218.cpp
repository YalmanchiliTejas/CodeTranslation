#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,K;
    cin >> N;
    char s[N];
    cin >> s;
    cin >> K;
    
    for(int i=0;i<N;i++){
        if(s[K-1]!=s[i]){
                cout << "*";
        }else{
            cout << s[i];
        }
        

    }
    
}
