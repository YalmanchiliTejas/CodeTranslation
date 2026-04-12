#include <bits/stdc++.h>
using namespace std;

constexpr int OK = 0;
constexpr int NG = -1;
int check(char *s, char *output, int64_t N, int64_t pos);
int test(char *s, char *output, int64_t N, int64_t pos);
int main(void) {
    int64_t N;
    char *s;
    char *output;
    int result;

    cin >> N;
    s = (char*)calloc(1,N+2);
    output = (char*)calloc(1,N+3);
    cin >> s;

    result = test(s, output, N, 0);
    if(result == OK) {
        cout << output << "\n";
    } else {
        cout << "-1\n";
    }
    free(s);
    return 0;
}

int test(char *s, char *output, int64_t N, int64_t pos) {
    int result;
    output[pos] = 'S';
    result = check(s,output,N,pos);
    if(result != OK) {
    output[pos] = '\0';
    output[pos] = 'W';
    result = check(s,output,N,pos);
    }
    return result;
}
int check(char *s, char *output, int64_t N, int64_t pos) {
    char neighbor;
    char chk;
    char judge;
    int result;
    
//printf("called pos:%ld output:%s\n", pos, output);
    // 真ん中チェック
    if(pos == (N-1)) {
        if(((s[pos] == 'o') && (output[pos] == 'S'))
            || ((s[pos] == 'x') && (output[pos] == 'W'))) {
            if(output[pos-1] == output[0]) {
            } else {
                return NG;
            }
        } else {
            if(output[pos-1] != output[0]) {
            } else {
                return NG;
            }
        }
    }

    //右側チェック
    if(pos > (N-3)) {
        neighbor = output[pos - N + 2];
    } else {
        neighbor = output[pos + 2];
    }
    if(neighbor) {
        if(pos == (N-1)) {
            judge = output[0];
            chk = s[0];
        } else {
            judge = output[pos+1];
            chk = s[pos+1];
        }
        if(judge) {
            if(judge == 'S'){ 
                chk = (chk == 'o') ? chk : '\0';
            } else {
                chk = (chk == 'x') ? chk : '\0';
            }
            if ((chk && (output[pos] == neighbor)) || ((!chk) && (output[pos] != neighbor) )) {
//printf("%d pos:%ld s:%s output:%s chk:%c neighbor:%c\n", __LINE__, pos, s, output, chk, neighbor);
            } else {
//printf("%d pos:%ld s:%s output:%s chk:%c neighbor:%c\n", __LINE__, pos, s, output, chk, neighbor);
                return NG;
            }
        }
    }
    //左側チェック
    if(pos < 2) {
        neighbor = output[pos -2 + N];
    } else {
        neighbor = output[pos - 2];
    }
    if(neighbor) {
        if(pos == 0) {
            judge = output[N-1];
            chk = s[N-1];
        } else {
            judge = output[pos-1];
            chk = s[pos-1];
        }
        if(judge) {
            if(judge == 'S'){
                chk = (chk == 'o') ? chk : '\0';
            } else {
                chk = (chk == 'x') ? chk : '\0';
            }

            if((chk && (output[pos] == neighbor)) || ((!chk) && (output[pos] != neighbor))) {
//printf("%d pos:%ld s:%s output:%s chk:%c neighbor:%c\n", __LINE__, pos, s, output, chk, neighbor);
            } else {
//printf("%d pos:%ld s:%s output:%s chk:%c neighbor:%c\n", __LINE__, pos, s, output, chk, neighbor);
                return NG;
            }
        }
    }
    if(pos == (N-1)) {
//printf("%d %s\n", __LINE__, output);
        return OK;
    }

//    for(int i=pos+1;i<N;i++) {
    int i=pos+1;
        output[i] = 'S';
        if(check(s, output, N, pos + 1) == OK) {
//printf("%d %s\n", __LINE__, output);
        return OK;
            return OK;
        }
        output[i] = '\0';
        output[i] = 'W';
        if(check(s, output, N, pos + 1) == OK) {
//printf("%d %s\n", __LINE__, output);
        return OK;
            return OK;
        }
        output[i] = '\0';
//    }

    return NG;
}
