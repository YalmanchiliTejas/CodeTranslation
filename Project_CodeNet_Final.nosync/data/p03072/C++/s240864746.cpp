//https://atcoder.jp/contests/abc124/tasks/abc124_b
#include <iostream>
using namespace std;

int main(){
    int N;

    cin >> N;

    int *H = new int[N];
    for(int i=0;i<N;i++){
        cin>>H[i];
    }

    int count=1;
    int Hill=H[0];
    for(int i=1;i<N;i++){
        if(Hill<=H[i]){
            count++;
            Hill=H[i];
        }
    }
    cout << count<<endl;
    return 0;
}