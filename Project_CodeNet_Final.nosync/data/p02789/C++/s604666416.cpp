#include<iostream>
#include<vector>
#define loop(n) for(int i=0; i<(n); i++)
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main(){
    int N,M;
    cin >> N >> M ;
    if(N == M){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}