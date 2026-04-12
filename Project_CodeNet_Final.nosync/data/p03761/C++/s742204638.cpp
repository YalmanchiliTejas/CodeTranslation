#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    char s = 'a';
    int n, count, _count, ind;

    cin >> n;
    vector<string> ve(n);
    for(int i = 0; i < n; i++) cin >> ve[i];

    while(s <= 'z'){
        count = 0;
        for(int j = 0; j < n; j++){
            _count = 0;
            ind = ve[j].find(s);
            while(ind != -1){
                ind = ve[j].find(s, ind + 1);
                _count++;
            }
            if(_count == 0){
                count = _count;
                break;
            }else{
                if(count > _count || j == 0) count = _count;
            }
        }
        for(int j = 0; j < count; j++) cout << s;
        s++;
    }
    cout << '\n';
}