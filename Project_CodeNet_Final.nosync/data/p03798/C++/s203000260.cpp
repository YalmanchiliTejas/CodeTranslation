#include <iostream>
#include <string>
#include<math.h>


using namespace std;


char tmp_answer[100000];

char decide_next(char answer, char left, char center){
    if(answer == 'o'){
        if(center == 'S') return left;
        else if(center == 'W'){
            if(left == 'W') return 'S';
            else return 'W';
        }
    }
    else if(answer == 'x'){
        if(center == 'S'){
            if(left == 'S') return 'W';
            else if (left == 'W') return 'S';
        }
        else return left;
    }
}


bool check_answer(int N, char s[], char first, char second){
    tmp_answer[0] = first;
    tmp_answer[1] = second;
    for(int i=2;i<N;i++){
        tmp_answer[i] = decide_next(s[i-1], tmp_answer[i-2], tmp_answer[i-1]);
    }
    if((tmp_answer[0] == decide_next(s[N-1], tmp_answer[N-2], tmp_answer[N-1]))
        and 
       (tmp_answer[1] == decide_next(s[0], tmp_answer[N-1], tmp_answer[0]))){
           return true;
       }
    else return false;
}


int main(void){
    int N;
    char s[100000];

    cin >> N;
    cin >> s;

    /*
    char first[4] = 'SSWW';
    char second[4] = 'SWSW';
    */

    if(check_answer(N, s, 'S', 'S')){
        cout << tmp_answer << endl;
        return 0;
    }
    if(check_answer(N, s, 'S', 'W')){
        cout << tmp_answer << endl;
        return 0;
    }
    if(check_answer(N, s, 'W', 'S')){
        cout << tmp_answer << endl;
        return 0;
    }
    if(check_answer(N, s, 'W', 'W')){
        cout << tmp_answer << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}