#include <iostream>
using namespace std;

string d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
string e[40] = {"100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000","101","010001","000011","10010001","000000","000001"};

string tb(int n){
    string res = "";
    int c = 5;
    char cc;
    while(c--){
        cc = n%2+'0';
        res = string(1, n%2+'0') + res;
        n /= 2;
    }
    return res;
}

bool isPrefix(string sc, string sp){
    int i;
    for(i = 0; sp[i] && i < sc.size(); i++){
        if( sc[i] != sp[i] ) return false;
    }
    return i == sc.size();
}

int main(){
    string s;
    int i, j;
    while( getline(cin, s) ){
        string c = string("");
        for(i = 0; i < s.size(); i++){
            int ind = d.find_first_of(s[i]);
            c += tb( ind );
        }
        i = 0;
        int len = c.size();
        while(i < len){
            string t = "";
            int can,rem, f = 0;
            while(i+f < len){
                can = 0;
                t += c[i+f];
                for(j = 0; j < 36; j++){
                    if( isPrefix(t, e[j]) ){
                        can++;
                        rem = j;
                    }
                }
                if( can == 1 ){
                    if( i+e[rem].size() <= len){
                        cout << d[rem];
                    }
                    i += e[rem].size()-1;
                    break;
                }
                f++;
            }
            i++;
        }
        cout << endl;
    }
    return 0;
}