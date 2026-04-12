#include<iostream>
#include<string>

using namespace std;

int main() {
    string left = "qwertasdfgzxcvb";
    string tmp;
    while (cin >> tmp && tmp != "#") {
        int j,n=0,pos; //1??§??????
        for(int i=0;i<tmp.length();i++) {
            char b = tmp[i];
            for(j=0;j<15;j++){
                if (b==left[j]) break;
            }
            if (i==0) {
                if (j==15) {
                    pos = 1;
                } else pos = 0;
            } else {
                if (pos == 1 && j != 15) {n++; pos = 0;}
                if (pos == 0 && j == 15) {n++; pos = 1;}
            }
        }
        cout << n << endl;
    }
}