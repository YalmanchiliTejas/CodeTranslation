#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

class FastIO {
    static const int BUF_SIZE = 1<<17;
    char inBuf[BUF_SIZE + 2];
    char *in, *inEnd = inBuf + BUF_SIZE;
    char outBuf[BUF_SIZE + 2];
    char *out, *outEnd = outBuf + BUF_SIZE;

    // stdinからBUFFER_SIZE分まで一気に読み込み、読み込んだサイズを返す
    size_t Load() {
        in = inBuf;
        size_t size = fread(inBuf, 1, BUF_SIZE, stdin);
        inBuf[size] = '\0';
        return size;
    }

    // lenの長さの文字列を出力した場合にバッファを超過するなら、バッファをリセットする
    void FlushIfNeed(int len) {
        if (out + len > outEnd) flush();
    }
    // lenの長さの文字列を入力した場合にバッファを超過するなら、バッファをリロードする
    void LoadIfNeed(int len) {
        if (in + len <= inEnd) return;

        unsigned long rest_size = inEnd - in;
        memcpy(inBuf, in, rest_size);
        size_t size = fread(inBuf + rest_size, 1, BUF_SIZE - rest_size, stdin);
        inBuf[rest_size + size] = '\0';
        in = inBuf;
    }

    char GetChar() {
        if (*in == '\0') {
            // これ以上読み込みできなかった場合はとりあえず0を返しておく
            if (Load() == 0) return 0;
        }
        return *in++;
    }
    void PutChar(char c) {
        FlushIfNeed(1);
        *out++ = c;
    }

    // 0以上の整数向けのscan
    template<typename T>
    void ScanNatural(T &x) {
        x = 0;

        // 数字が出てくるまでスキップ
        char c = GetChar();
        while(!isdigit(c)) c = GetChar();

        // 数値に変換
        LoadIfNeed(21);
        x = c&15;
        for (c = *in++; isdigit(c); c = *in++) {
            // c = '0'~'9' = 48~57 のとき、 c & 15 = c - '0'
            x = x * 10 + (c&15);
        }
    }
    // 負数を考慮する整数値scan
    template<typename T>
    void ScanInteger(T &x) {
        x = 0;

        // -記号か数字が出てくるまでスキップ
        char c = GetChar();
        while (c != '-' && !isdigit(c)) c = GetChar();

        // -記号の処理
        bool minus = c == '-';
        if (minus) c = GetChar();

        LoadIfNeed(21);
        x = c&15;
        for (c = *in++; isdigit(c); c = *in++) {
            x = x * 10 + (c&15);
        }
        if (minus) x = -x;
    }

    // 長さの分かっている文字列の出力(lenはBUFFER_SIZE以下)
    void PrintString(const char *s, size_t len) {
        char *new_out_pos = out + len;
        if (new_out_pos > outEnd) {
            flush();
            new_out_pos = out + len;
        }
        memcpy(out, s, len);
        out = new_out_pos;
    }
    // 非負整数値の出力
    template<typename T>
    void PrintNatural(T x) {
        char digit[21], *d_start, *d_end;
        d_start = d_end = digit + 21;
        // x = 0 の場合も0を出力する必要があるので、do whileで最低1桁は処理する
        do {
            // 上の桁に向かって処理していくので、表示順序と逆になる
            --d_start;
            *d_start = x % 10 + '0';
            x /= 10;
        } while (x != 0);

        // 出力
        PrintString(d_start, d_end - d_start);
    }
    // 整数値の出力
    template<typename T>
    void PrintInteger(T x) {
        if (x < 0) {
            PutChar('-');
            x = -x;
        }
        PrintNatural(x);
    }

public:
    // 出力バッファの中身をstdoutに流し出し、出力バッファをリセットする
    void flush() {
        fwrite(outBuf, out - outBuf, 1, stdout);
        out = outBuf;
    }

    FastIO() {
        in = inEnd;
        out = outBuf;
    }
    ~FastIO() {flush();}

    void scan(std::string &s) {
        char c = GetChar();
        while (!isprint(c)) c = GetChar();

        s.clear();
        for (; isprint(c); c = GetChar()) {
            s.push_back(c);
        }
    }
    void scan(ll &x) {ScanInteger(x);}
    void scan(int &x) {ScanInteger(x);}
    void scan(ull &x) {ScanNatural(x);}
    void scan(uint &x) {ScanNatural(x);}
    template<typename First, typename ... Ints>
    void scan(First &arg, Ints&... rest) {
        scan(arg);
        scan(rest...);
    }

    void print(const char *s) {
        size_t len = strlen(s);

        // バッファサイズより大きい文字列を出力しようとした場合は、stdoutにそのまま流す
        if (len > BUF_SIZE) {
            flush();
            printf("%s", s);
            return;
        }

        PrintString(s, len);
    }
    void print(std::string &s) {PrintString(s.c_str(), s.size());}
    void print(char c) {PutChar(c);}
    void print(int x) {PrintInteger(x);}
    void print(ll x) {PrintInteger(x);}
    void print(uint x) {PrintNatural(x);}
    void print(ull x) {PrintNatural(x);}
    template <class T>
    void print(std::vector<T> &v) {
        if (v.size() == 0) return;
        print(*v.begin());
        for (auto it = ++v.begin(); it != v.end(); ++it) {
            PutChar(' ');
            print(*it);
        }
    }
    template <class T>
    void print(std::vector< std::vector<T> > &grid) {
        if (grid.size() == 0) return;
        print(*grid.begin());
        for (auto it = ++grid.begin(); it != grid.end(); ++it) {
            PutChar('\n');
            print(*it);
        }
    }
    template<typename First, typename ... Ints>
    void print(First arg, Ints... rest) {
        print(arg);
        PutChar(' ');
        print(rest...);
    }
    template <typename T>
    void printl(T t) {
        print(t);
        PutChar('\n');
    }
    template <typename First, typename ... Ints>
    void printl(First arg, Ints... rest) {
        print(arg);
        PutChar(' ');
        printl(rest...);
    }

    void SayYes() {PrintString("Yes\n", 4);}
    void SayNo() {PrintString("No\n", 3);}
} io;



int main() {
    string s; io.scan(s);
    
    if (s.find('A') != string::npos && s.find('B') != string::npos) {
        io.SayYes();
    }
    else {
        io.SayNo();
    }
    return 0;
}
