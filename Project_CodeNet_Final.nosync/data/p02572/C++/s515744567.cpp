#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<random>
#include<bitset>


using namespace std;

#define rep(i,n) for(int i=0;i<n;i++) //0から
#define REP(i,n) for(int j=i;j<n;j++) //iから

typedef long long ll;



//英字ならture、数字ならfalse
bool isalpha(char s){
    if(('A'<=s&&s<='Z')||('a'<=s&&s<='z')){
        return 1;
    }else{
        return 0;
    }
}
//全ての文字が英字ならture、数字ならfalse
bool Isalpha(string s){
    ll n;
    bool tmp = true;
    rep(i,n){
        if(isalpha(s[i])){
            tmp = false;
        }
    }
    return tmp;
}




using Graph = vector<vector<ll>>;



//cout<<fixed<<setprecision(10);

ll binary_search(vector<ll> a, ll n, ll key){
    ll right = n, left = -1;
    ll md = (right + left) / 2;

    while(right - left > 1){
        if(a[md] <= key){
            right = md;
        }else{
            left = md;
        }
        md = (right + left) / 2;
    }
    if(left == -1) return -1; //無い場合
    return right;
}

#define MOD 1000000007

ll INFLL =  pow(10,9)+1;




string periodic_table[104] = {
    "None","H(1)","He(2)", //2
    "Li(3)","Be(4)","B(5)","C(6)","N(7)","O(8)","F(9)","Ne(10)", //10
    "Na(11)","Mg(12)","Al(13)","Si(14)","P(15)","S(16)","Cl(17)","Ar(18)", //18
    "K(19)","Ca(20)","Sc(21)","Ti(22)","V(23)","Cr(24)","Mn(25)","Fe(26)","Co(27)","Ni(28)","Cu(29)","Zn(30)","Ga(31)","Ge(32)","As(33)","Se(34)","Br(35)","Kr(36)", //36
    "Rb(37)","Sr(38)","Y(39)","Zr(40)","Nb(41)","Mo(42)","Tc(43)","Ru(44)","Rh(45)","Pd(46)","Ag(47)","Cd(48)","In(49)","Sn(50)","Sb(51)","Te(52)","I(53)","Xe(54)", //54
    "Cs(55)","Ba(56)","La(57)","Ce(58)","Pr(59)","Nd(60)","Pm(61)","Sm(62)","Eu(63)","Gd(64)","Tb(65)","Dy(66)","Ho(67)","Er(68)","Tm(69)","Yb(70)","Lu(71)","Hf(72)","Ta(73)","W(74)","Re(75)","Os(76)","Ir(77)","Pt(78)","Au(79)","Hg(80)","Tl(81)","Pb(82)","Bi(83)","Po(84)","At(85)","Rn(86)", //86
    "Fr(87)","Ra(88)","Ac(89)","Th(90)","Pa(91)","U(92)","Np(93)","Pu(94)","Am(95)","Cm(96)","Bk(97)","Cf(98)","Es(99)","Fm(100)","Md(101)","No(102)" //102
};

int main(){
    ll n,sum=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans = 0;
    rep(i,n){
        sum -= a[i];
        ll tmp = a[i]*(sum%MOD);
        tmp%=MOD;
        ans+=tmp;
        ans%=MOD;
    }
    ans%=MOD;
    cout<<ans<<endl;


    return 0;
}

