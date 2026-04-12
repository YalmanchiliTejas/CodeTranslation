#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;


int main(){
    int N;
    cin >> N;
    deque<int> ans;
    for(int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        if(i % 2){
            ans.push_back(a);
        }else{
            ans.push_front(a);
        }
    }
    for(int i = 0; i < N; i++){
        int j;
        if(N % 2){
            j = i;
        }else{
            j = N - 1 - i;
        }
        cout << (i?" ":"") << ans[j];
    }cout << endl;

    return 0;
}