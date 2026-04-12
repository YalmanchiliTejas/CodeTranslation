#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    string right="yuiophjklnm";
    cin >> s;
    while(s.at(0)!='#'){
        vector<int> Right(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(find(right.begin(),right.end(),s.at(i))==right.end()){
                Right.at(i)=1;
            }
        }
        int count=0;
        for(int i=1;i<Right.size();i++){
            if(Right.at(i)!=Right.at(i-1)) count++;
        }
        cout << count << endl;
        cin >> s;
    }
}
