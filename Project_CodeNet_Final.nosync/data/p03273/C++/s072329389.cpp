/*
    Converted by scratch2cpp (https://github.com/yos1up/scratch2cpp).
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define debug cerr << "--" << __LINE__ << "--" << "\n"
using namespace std;

const double EPS = 1e-8;

static int roundToInt(double x){
    return (x < 0) ? -(int)(-x + 0.5) : (int)(x + 0.5);
}


class Var{ // NOTE: immutable
public:
    string sval;
    double dval;
    enum VarType {STRING = 0, NUMBER = 1};
    VarType type;
    enum NumericState {UNKNOWN = -1, STRINGY = 0, NUMERIC = 1};
    mutable NumericState numericState;

    Var(){sval = ""; type = STRING; numericState = STRINGY;} // represent null?
    Var(string s){
        sval = s; type = STRING; numericState = UNKNOWN;
    }
    Var(double d){dval = d; type = NUMBER; numericState = NUMERIC;}
    Var(const Var &v){
        sval = string(v.sval); dval = v.dval;
        type = v.type; numericState = v.numericState;
    }
    static bool isNumericString(const string &s) {
        char* ep;
        strtod(s.c_str(), &ep);
        return !ep || !*ep;
        // TODO: In Scratch '000' is regarded as non-numeric (but here regarded as numeric)
    }
    bool isNumeric() const{
        if (type == NUMBER) return true;
        if (numericState != UNKNOWN) return numericState == NUMERIC;
        bool numeric = isNumericString(sval);
        numericState = (numeric) ? NUMERIC : STRINGY;
        return numeric;
    }
    double asNumber() const{
        if (type == NUMBER) return dval;
        return (isNumeric()) ? atof(sval.c_str()) : 0.0;
    }
    static bool isNearInteger(const double &x){
        return fabs(round(x) - x) < EPS;
        // TODO: allow integer type in Var class
    }
    static bool isNearNumber(const double &x, const double &y){
        return fabs(x - y) < EPS;
    }
    string asString() const{
        if (type == STRING) return sval;
        if (isNearInteger(dval)) return to_string(roundToInt(dval));
        return to_string(dval);
    }
    Var operator+(const Var &y) const{
        return Var(this->asNumber() + y.asNumber());
    }
    Var operator+=(const Var &y){
        *this = *this + y;
        return *this;
    }
    Var operator-(const Var &y) const{
        return Var(this->asNumber() - y.asNumber());
    }
    Var operator*(const Var &y) const{
        return Var(this->asNumber() * y.asNumber());
    }
    Var operator/(const Var &y) const{
        return Var(this->asNumber() / y.asNumber());
    }
    Var operator%(const Var &y) const{
        return Var(fmod(this->asNumber(), y.asNumber()));
    }
    bool operator<(const Var &y) const{
        if (this->isNumeric() && y.isNumeric()){
            return this->asNumber() < y.asNumber();
        }// compare as number if both can be interpreted as numeric
        return this->asString() < y.asString();
    }
    bool operator>(const Var &y) const{
        return y < *this;
    }
    bool operator==(const Var &y) const{
        if (this->isNumeric() && y.isNumeric()){
            return this->asNumber() == y.asNumber();
        }// compare as numeric if both are numeric
        return this->asString() == y.asString();
    }
    friend ostream& operator << (ostream& os, const Var& p);
    friend istream& operator >> (istream& is, const Var& p);
};
ostream& operator << (ostream& os, const Var& p){
    os << p.asString();
    return os;
}
istream& operator >> (istream& is, Var& p){
    string s; is >> s; p = Var(s);
    return is;
}

Var letterOf(Var index, Var sourceString){
    /* index: 1-origined */
    string str = sourceString.asString();
    int idx = (int)(index.asNumber() - 1);
    // seem to be dirty but Scratch seems to do like this.
    // ex. letterOf(0.01, "world") == "w", letterOf(1.99, "world") == "w", letterOf(5.99, "world") == "d"
    if (0 <= idx && idx < str.size()) return Var(str.substr(idx, 1));
    return Var();
}

class VarList{
public:
    vector<Var> data;
    VarList(const vector<Var> &x) { data = x; }
    void push_back(const Var &x){ data.push_back(x); }
    void pop_back(){ data.pop_back(); }
    void clear(){ data.clear(); }
    int size(){ return (int) data.size(); }
    Var getLineOfList(const Var &index) const{
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        // (unlike 'letterOf', index==0.9 does not work.)
        if (0 <= idx && idx < data.size()) return data[idx];
        return Var();
    }
    void setLineOfListTo(const Var &index, const Var &v){
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        if (0 <= idx && idx < data.size()) data[idx] = v;
    }
    void deleteLineOfList(const Var &index){
        /* index: 1-origined */
        string kwd = index.asString();
        if (kwd == "all"){
            data.clear();
        }else if (kwd == "last"){
            data.pop_back();
        }else{
            int idx = (int)index.asNumber() - 1;
            if (0 <= idx && idx < data.size()) data.erase(data.begin() + idx);
        }
    }
    void insertAtIndexOfList(const Var &item, const Var &index){
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        if (0 <= idx && idx <= data.size()) data.insert(data.begin() + idx, item);   
    }
    void insertAtRandomOfList(const Var &item){
        int idx = rand() % (data.size() + 1);
        data.insert(data.begin() + idx, item);
    }
    string asString() const{
        /* concatenate elements of list with space */
        // TODO: concatenated without spaces only if all elements are single characters.
        // (Is it an official bug? (or feature?))
        string ret;
        for(int i=0;i<data.size();i++){
            if (i > 0) ret += ' ';
            ret += data[i].asString();
        }
        return ret;        
    }
    int itemNumOfList(const Var &item) const{
        auto itr = find(data.begin(), data.end(), item);
        if (itr == data.end()) return 0;
        return 1 + (int)(itr - data.begin());
        /* index: 1-origined */
    }
    friend ostream& operator << (ostream& os, const VarList& p);
};
ostream& operator << (ostream& os, const VarList& p){
    os << p.asString();
    return os;
}

double randUniform(double x, double y){
    if (x > y) return randUniform(y, x);
    if (Var::isNearInteger(x) && Var::isNearInteger(y)){
        int xi = roundToInt(x), yi = roundToInt(y);
        return xi + rand() % (yi - xi + 1);
    }else{
        return x + (y - x) * (0.0 + rand()) / RAND_MAX;
    }
}

Var buf_answer; // for "answer"

// ============================= Scripts =============================

// variable declaration
Var var_H(3);
Var var_W(3);
Var var_flg(1);
Var var_h(4);
Var var_w(4);
Var var_answer("..#");

// list declaration
VarList list_a({Var("#"), Var("."), Var("."), Var("."), Var("#"), Var("."), Var("."), Var("."), Var("#")});

// prototype declaration of functions
int main();
int func_init();
int func_main();

// contents of functions
int main(){
    func_init();
    cin >> buf_answer;
    var_H = buf_answer;
    cin >> buf_answer;
    var_W = buf_answer;
    for (int tqvhtfou=0;tqvhtfou<var_H.asNumber();tqvhtfou++){
        cin >> buf_answer;
        var_w = Var(1);
        for (int iegubiio=0;iegubiio<var_W.asNumber();iegubiio++){
            list_a.push_back(letterOf(var_w, buf_answer));
            var_w = (var_w + Var(1));
        }
    }
    func_main();
    return 0;
}

int func_init(){
    list_a.clear();
    return 0;
}

int func_main(){
    var_h = Var(1);
    for (int fkzrhukn=0;fkzrhukn<var_H.asNumber();fkzrhukn++){
        var_flg = Var(0);
        var_w = Var(1);
        for (int pebsqdph=0;pebsqdph<var_W.asNumber();pebsqdph++){
            if ((var_flg == Var(0))){
                if ((list_a.getLineOfList((((var_h - Var(1)) * var_W) + var_w)) == Var("#"))){
                    var_flg = Var(1);
                }
            }
            var_w = (var_w + Var(1));
        }
        if ((var_flg == Var(0))){
            var_w = Var(1);
            for (int loisphdu=0;loisphdu<var_W.asNumber();loisphdu++){
                list_a.setLineOfListTo((((var_h - Var(1)) * var_W) + var_w), Var("X"));
                var_w = (var_w + Var(1));
            }
        }
        var_h = (var_h + Var(1));
    }
    var_w = Var(1);
    for (int rzklnhqs=0;rzklnhqs<var_W.asNumber();rzklnhqs++){
        var_flg = Var(0);
        var_h = Var(1);
        for (int zivxxdyo=0;zivxxdyo<var_H.asNumber();zivxxdyo++){
            if ((var_flg == Var(0))){
                if ((list_a.getLineOfList((((var_h - Var(1)) * var_W) + var_w)) == Var("#"))){
                    var_flg = Var(1);
                }
            }
            var_h = (var_h + Var(1));
        }
        if ((var_flg == Var(0))){
            var_h = Var(1);
            for (int szsipuik=0;szsipuik<var_H.asNumber();szsipuik++){
                list_a.setLineOfListTo((((var_h - Var(1)) * var_W) + var_w), Var("X"));
                var_h = (var_h + Var(1));
            }
        }
        var_w = (var_w + Var(1));
    }
    var_h = Var(1);
    for (int ydunkapc=0;ydunkapc<var_H.asNumber();ydunkapc++){
        var_w = Var(1);
        var_answer = Var("");
        for (int qsbfzmtj=0;qsbfzmtj<var_W.asNumber();qsbfzmtj++){
            if ((!(list_a.getLineOfList((((var_h - Var(1)) * var_W) + var_w)) == Var("X")))){
                var_answer = Var(var_answer.asString() + list_a.getLineOfList((((var_h - Var(1)) * var_W) + var_w)).asString());
            }
            var_w = (var_w + Var(1));
        }
        var_h = (var_h + Var(1));
        if ((!(var_answer == Var("")))){
            cout << var_answer << endl;
        }
    }
    return 0;
}

