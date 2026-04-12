#include<iostream>
using namespace std;

int main(){
    int ans = -1;
    int chair, person, space;
    cin >> chair >> person >> space;

    chair -= space;

    while(chair >= 0){
        chair -= space + person;
        ans++;
    }

    cout << ans;
}
