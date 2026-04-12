#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

map<char,string> b;

string ch1(string s){
    string ret="";
    rep(i,s.size()){
        ret+=b[s[i]];
    }
    return ret;
}



string solve(string s){
    string ret;

    int bef=-1;
    for(int i=0;i<s.size();){
        if(bef==i)break;
        bef=i;
        if( s.size() - i>=3 ){
            if( s.substr(i,3)=="101" )ret+=' ',i+=3;
            if( s.substr(i,3)=="110" )ret+='E',i+=3;
            if( s.substr(i,3)=="111" )ret+='P',i+=3;
        }
        if( s.size() - i>=4 ){
            if( s.substr(i,4)=="0101" )ret+='C',i+=4;
            if( s.substr(i,4)=="0001" )ret+='D',i+=4;
            if( s.substr(i,4)=="0111" )ret+='I',i+=4;
            if( s.substr(i,4)=="0110" )ret+='K',i+=4;
            if( s.substr(i,4)=="1000" )ret+='R',i+=4;
        }
        if( s.size() - i>=5 ){
            if( s.substr(i,5)=="01001" )ret+='F',i+=5;
            if( s.substr(i,5)=="00100" )ret+='L',i+=5;
            if( s.substr(i,5)=="00101" )ret+='O',i+=5;
            if( s.substr(i,5)=="00110" )ret+='S',i+=5;
            if( s.substr(i,5)=="00111" )ret+='T',i+=5;
        }
        if( s.size() - i>=6 ){
            if( s.substr(i,6)=="000000" )ret+='\'',i+=6;
            if( s.substr(i,6)=="000011" )ret+=',',i+=6;
            if( s.substr(i,6)=="010001" )ret+='.',i+=6;
            if( s.substr(i,6)=="000001" )ret+='?',i+=6;
            if( s.substr(i,6)=="100101" )ret+='A',i+=6;
            if( s.substr(i,6)=="010000" )ret+='H',i+=6;
            if( s.substr(i,6)=="000010" )ret+='W',i+=6;

        }
        if( s.size() - i>=8 ){
            if( s.substr(i,8)=="10010001" )ret+='-',i+=8;
            if( s.substr(i,8)=="10011010" )ret+='B',i+=8;
            if( s.substr(i,8)=="10011011" )ret+='G',i+=8;
            if( s.substr(i,8)=="10011000" )ret+='J',i+=8;
            if( s.substr(i,8)=="10011001" )ret+='M',i+=8;
            if( s.substr(i,8)=="10011110" )ret+='N',i+=8;
            if( s.substr(i,8)=="10011111" )ret+='Q',i+=8;
            if( s.substr(i,8)=="10011100" )ret+='U',i+=8;
            if( s.substr(i,8)=="10011101" )ret+='V',i+=8;
            if( s.substr(i,8)=="10010010" )ret+='X',i+=8;
            if( s.substr(i,8)=="10010011" )ret+='Y',i+=8;
            if( s.substr(i,8)=="10010000" )ret+='Z',i+=8;
        }
    }
    
    return ret;
}


int main() {

    
    b['A'] ="00000";
    b['B'] ="00001";
    b['C'] ="00010";
    b['D'] ="00011";
    b['E'] ="00100";
    b['F'] ="00101";
    b['G'] ="00110";
    b['H'] ="00111";
    b['I'] ="01000";
    b['J'] ="01001";
    b['K'] ="01010";
    b['L'] ="01011";
    b['M'] ="01100";
    b['N'] ="01101";
    b['O'] ="01110";
    b['P'] ="01111";
    b['Q'] ="10000";
    b['R'] ="10001";
    b['S'] ="10010";
    b['T'] ="10011";
    b['U'] ="10100";
    b['V'] ="10101";
    b['W'] ="10110";
    b['X'] ="10111";
    b['Y'] ="11000";
    b['Z'] ="11001";
    b[' '] ="11010";
    b['.'] ="11011";
    b[','] ="11100";
    b['-'] ="11101";
    b['\'']="11110";
    b['?'] ="11111";

    string s;
    while(getline(cin,s)){
        string ans=ch1(s);
        cout<<solve(ans)<<endl;
    }
    return 0;
}