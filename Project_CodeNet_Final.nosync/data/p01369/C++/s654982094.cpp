#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	while(1){
        string a;
        cin >> a;
        if(a[0] == '#') break;
        string word = "yuiophjklnm";
        bool flg[50] = {0};
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < word.size(); j++){
                if(a[i] == word[j]) flg[i] = 1;
            }
        }
        int cnt = 0;
        for(int i = 1; i < a.size(); i++){
            if(flg[i-1] != flg[i]) cnt++;
        }
        cout << cnt << endl;
	}
	return 0;
}