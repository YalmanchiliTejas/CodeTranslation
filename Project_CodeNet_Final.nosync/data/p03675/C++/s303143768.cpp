#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

int main() {
    
    int n;
    cin >> n;

    deque<int> ans;
    REP(i,n) {
        int a; cin >> a;
        if(i%2==0) ans.push_back(a);
        else ans.push_front(a);
    }

    REP(i,n) {
        if(n%2 == 1){
            cout << ans.back() << " ";
            ans.pop_back();
        } else {
            cout << ans.front() << " ";
            ans.pop_front();
        }
    }

    cout << endl;
    
    return 0;
}