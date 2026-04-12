#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<char> S(3);

    for(int i=0; i<S.size(); i++)
    {
        cin >> S.at(i);
    }

    bool can=true;

    if((S.at(0)==S.at(1)) && (S.at(1)==S.at(2)))
    {
        can = false;
    }

    if(can)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}