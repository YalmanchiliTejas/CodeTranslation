#include <iostream>
#include <map>

using namespace std;

const char lef[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
const char rig[] = {'y','u','i','o','p','h','j','k','l','n','m'};
const int num_l = 15;
const int num_r = 11;

int main()
{
    string s;

    map<char, bool> qwe;
    for (int i = 0; i < num_l; i++)
        qwe[lef[i]] = true;
    for (int i = 0; i < num_r; i++)
        qwe[rig[i]] = false;

    while (cin >> s, s != "#") {
        int cnt = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (qwe[s[i]] ^ qwe[s[i + 1]])
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}