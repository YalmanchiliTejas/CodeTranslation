#include <iostream>
#include <map>

using namespace std;

int main() {
        int n;
        string s;
        cin >> n >> s;

        map< int, int > mp;
        map< int, int > tmp;
        for (size_t i=0; i<s.size(); ++i) {
                if (mp.find(s[i]-'a')==mp.end()) {
                        mp[s[i]-'a'] = 1;
                } else {
                        mp[s[i]-'a']++;
                }
        }

        for (size_t j=0; j<n-1; ++j) {
                cin >> s;
                tmp.clear();
                for (size_t i=0; i<s.size(); ++i) {
                        if (tmp.find(s[i]-'a')==tmp.end()) {
                                tmp[s[i]-'a'] = 1;
                        } else {
                                tmp[s[i]-'a']++;
                        }
                }
                for (int i=0; i<26; ++i) {
                        map<int, int>::iterator it;
                        it = mp.find(i);
                        if (tmp.find(i)==tmp.end()) {
                                if (it != mp.end()) {
                                        mp.erase(it);
                                }
                        } else {
                                if (it != mp.end()) {
                                        mp[i] = min(mp[i], tmp[i]);
                                }
                        }
                }
        }

        if (mp.size()==0) cout << endl;
        else {
                for (int i=0; i<26; ++i) {
                        if (mp.find(i)!=mp.end()) {
                                for (int j=0; j<mp[i]; ++j) {
                                        cout << char(i+'a');
                                }
                        }
                }
        }
        return 0;
}
