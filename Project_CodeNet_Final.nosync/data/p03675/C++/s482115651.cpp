#include<iostream>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int n, ans = 0;
	cin >> n;
    int k;
    if(n % 2 == 0) k = 1;
    else k = -1;
    list<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(k == -1) a.push_front(x);
        else a.push_back(x);
        k = -k;
    }
    string s = "";
    for(auto&& i : a){
        s += to_string(i) + " ";
    }
    s.erase(s.size() - 1, 1);
    cout << s << endl;
	return 0;
}
