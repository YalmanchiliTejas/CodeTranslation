#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    bool flg = 0;
	while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        if(flg == 1) cout << endl;
        char team[20][100] = {0};
        int ten[20] = {0};
        int score[20] = {0};
        for(int i = 0; i < n; i++){
            getchar();
            scanf("%s",team[i]);
            int a,b,c;
            cin >> a >> b >> c;
            ten[i] = 3 * a + c;
            score[i] = ten[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ten[i] > ten[j]){
                    swap(ten[i],ten[j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ten[i] == score[j]){
                    cout << team[j] << ',' <<  score[j] << endl;
                    score[j] = -1;
                }
            }
        }

        flg = 1;
	}
	return 0;
}