#include<iostream>
#include<string>
using namespace std;

void zooprint(string s){
    for(int i=0; i<s.size()-1; i++){
        cout << s[i];
    }
    cout << endl;
}

char forward(char a, char b, char c){
    if( b=='S' ){

        if( c=='o' ){
            if( a=='S' ){
                return 'S';
            }else if( a=='W' ){
                return 'W';
            }
        }else if( c=='x' ){
            if( a=='S' ){
                return 'W';
            }else if( a=='W' ){
                return 'S';
            }            
        }
    }else if( b=='W' ){

        if( c=='o' ){
            if( a=='S' ){
                return 'W';
            }else if( a=='W' ){
                return 'S';
            }
        }else if( c=='x' ){
            if( a=='S' ){
                return 'S';
            }else if( a=='W' ){
                return 'W';
            }            
        }
    }
    return 'X';
}

int check( char af, char bf, string s ){
    string animal;
    char a, b, c, x;

    for(int i=1; i<s.size(); i++){
        if(i==1){
            animal += af;
            animal += bf;
        }
        a=animal[i-1];
        b=animal[i];
        c=s[i];
        x=forward(a,b,c);
        if( x=='X' ){
            cout << "forward error" << endl;
            return 2;
        }else{
            animal += x;
        }
    }
    a=animal[s.size()];
    if( a==animal[0] ){
        x=forward( animal[s.size()-1], a, s[0] );
        if( x==animal[1] ){
            zooprint(animal);
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int main(){
    int N;
    string s;
    int iflag;
    cin >> N;
    cin >> s;

    iflag=check( 'S', 'S', s );
    if(iflag) return 0;
    iflag=check( 'S', 'W', s );
    if(iflag) return 0;    
    iflag=check( 'W', 'S', s );
    if(iflag) return 0;
    iflag=check( 'W', 'W', s );
    if(iflag) return 0;

    cout << -1 << endl;

    return 0;
}