#include <iostream>
#include <string>
using namespace std;

string t = "yuiophjklnm";

int main()
{
    while(true){
        string s;
        cin >> s;
        if(s == "#") break;
        int n = s.size();
        int ans = 0;
        int lr = -1;
        for(int i = 0; i < n; i++){
            bool r = false;
            for(int j = 0; j < 11; j++){
                if(s[i] == t[j]) r = true;
            }
            if((lr == 0 && r) || (lr == 1 && !r)) ans++;
            if(r) lr = 1;
            else lr = 0;
        }
        cout << ans << endl;
    }
}

