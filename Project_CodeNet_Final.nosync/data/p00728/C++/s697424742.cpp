#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> s){
    sort(s.begin(),s.end());
    int al = 0;
    for(int i=1;i<s.size()-1;i++){
        al += s[i];
    }
    return al / (s.size()-2);
}
int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        cout << solve(s) << endl;
    }
    return 0;
}