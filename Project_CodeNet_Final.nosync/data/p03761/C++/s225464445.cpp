#include <bits/stdc++.h>

using namespace std;


int main(void){

    long long n;
    cin >> n;

    vector<string> s_i(n);
    for(int i=0; i<n; i++) {
        cin >> s_i[i];
    }

    vector<int> alpha_count;
    for(char c='a'; c<='z'; c++) {
        int min = 100;
        for(int i=0; i<s_i.size(); i++) {
            size_t count = std::count(s_i[i].begin(), s_i[i].end(), c);
//              cout << i << " " << c << " " << count << endl;
            if((int)count == 0) min = -1;
            if(min > (int)count) min = (int)count;
        }
//        cout << min << endl;
        alpha_count.push_back(min);
    }


    for(char c='a'; c<='z'; c++) {
        if(alpha_count[c-'a'] != 100) {
            for(int i=0; i<alpha_count[c-'a']; i++) {
                cout << c;
            }
        }
    }
    
    cout << endl;
    
    return 0;
}
