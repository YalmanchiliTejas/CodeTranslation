#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

stringstream ans;
stringstream tmp;
int len;
int i;
void search_code (string S, char a) {
    if (tmp.str() == S) {
        ans << a;
        len = 0;
        tmp.str("");
        tmp.clear(stringstream::goodbit);
    }
}

void input_code (char a) {
    //dump(i);
    tmp << a;
    i++;
    len++;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    while(getline(cin, S)){
        tmp.str("");
        tmp.clear(stringstream::goodbit);
        ans.str("");
        ans.clear(stringstream::goodbit);
    i = 0;
    len = 0;

    // ??\???????????????????????°??????
    stringstream str;
    string Cstr;
    while (S[i] != '\0') {
        int tmp;
        if (S[i] >= 'A' && S[i] <= 'Z') tmp = S[i] - 'A';
        else if (S[i] == ' ') tmp = 26;
        else if (S[i] == '.') tmp = 27;
        else if (S[i] == ',') tmp = 28;
        else if (S[i] == '-') tmp = 29;
        else if (S[i] == '\'') tmp = 30;
        else if (S[i] == '?') tmp = 31;
        str << static_cast<bitset<5> >(tmp);
        i++;
    }
    Cstr = str.str();
    //dump(Cstr);

    i = 0;
    while (i < Cstr.length()) {
        //dump(ans.str());
        //dump(tmp.str());
        while (len < 3) {
            input_code(Cstr[i]);
        }
        //dump(tmp.str());
        //len == 3;
        search_code("101", ' ');
        search_code("110", 'E');
        search_code("111", 'P');
        if ((tmp.str()).length() != 0) input_code(Cstr[i]);
        else continue;

        //dump(tmp.str());
        //len == 4;
        search_code("0101", 'C');
        search_code("0001", 'D');
        search_code("0111", 'I');
        search_code("0110", 'K');
        search_code("1000", 'R');

        if ((tmp.str()).length() != 0) input_code(Cstr[i]);
        else continue;

        //dump(tmp.str());
        //len == 5;
        search_code("01001", 'F');
        search_code("00100", 'L');
        search_code("00101", 'O');
        search_code("00110", 'S');
        search_code("00111", 'T');

        if ((tmp.str()).length() != 0) input_code(Cstr[i]);
        else continue;

        //dump(tmp.str());
        //len == 6;
        search_code("000000", '\'');
        search_code("000011", ',');
        search_code("010001", '.');
        search_code("000001", '?');
        search_code("010000", 'H');
        search_code("000010", 'W');
        search_code("100101", 'A');

        if ((tmp.str()).length() != 0) {
            input_code(Cstr[i]);
            input_code(Cstr[i]);
        }
        else continue;

       //dump(tmp.str());
       //len == 8;
       search_code("10010001", '-');
       search_code("10011010", 'B');
       search_code("10011011", 'G');
       search_code("10011000", 'J');
       search_code("10011001", 'M');
       search_code("10011110", 'N');
       search_code("10011111", 'Q');
       search_code("10011100", 'U');
       search_code("10011101", 'V');
       search_code("10010010", 'X');
       search_code("10010011", 'Y');
       search_code("10010000", 'Z');

       if ((tmp.str()).length() != 0) input_code(Cstr[i]);
       else continue;
    }

    //cout << tmp.str() << endl;
    cout << ans.str() << endl;
    }
    return 0;
}