#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<map<char, int> > vec(N);
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++) {
        vec[0][str[i]]++;
    }
    for(int n=1; n<N; n++) {
        cin >> str;
        
        for(int i=0; i<str.size(); i++) {
            if(vec[n][str[i]]<vec[n-1][str[i]]) {
                vec[n][str[i]]++;
            }
        }
    }
    
    string ans;
    for(auto itr=vec[N-1].begin(); itr!=vec[N-1].end(); itr++) {
        for(int i=0; i<itr->second; i++) {
            ans += itr->first;
        }
    }
    
    cout << ans << endl;


    return 0;
    
}