#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    long long int ans = 0;
    for(int ab=1; ab<n; ab++){// A - B
        //cout << ab << " : ";
        long long int score = 0;
        set<int> visited;
        for(int k=0; k<n; k++){
            if((n-1) - k*ab <= ab) break;
            if(visited.find(k * ab) != visited.end()) break;
            visited.insert(k * ab);
            if(visited.find((n-1) - k * ab) != visited.end()) break;
            visited.insert((n-1) - k * ab);

            score += s[k * ab];
            score += s[(n-1) - k * ab];
            ans = max(ans, score);
        }
        //cout << score << endl;
    }
    cout << ans << endl;
    return 0;
}