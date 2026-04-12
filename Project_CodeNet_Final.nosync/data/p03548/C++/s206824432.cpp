#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int newchair = x-z;
    int people_length = y+z;
    int answer = newchair/people_length;
    cout << answer << endl;
}