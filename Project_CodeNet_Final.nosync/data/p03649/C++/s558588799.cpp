#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct DecreasingArrayNaive{
    int N;
    vector<LL> As;
    DecreasingArrayNaive(int _N, const vector<LL> &_As): N(_N), As(_As){}
    LL do_K(LL K){
        for (int i = 0; i != K + 1; ++i){
            auto it = max_element(As.begin(), As.end());
            if (*it < N) return i;
            *it -= N + 1;
            for (int j = 0; j != N; ++j) ++As[j];
        }
        return -1;
    }
};

struct DecreasingArray{
    int N;
    vector<LL> As;
    vector<LL> ks;
    vector<int> gs;
    vector<vector<LL>> AAs;
    DecreasingArray(int _N, const vector<LL> &_As):N(_N), As(_As) {
        init();
    }
    void init(){
        sort(As.begin(), As.end(), greater<LL>());
        AAs.push_back(As);
        ks.push_back(0);
        auto g = find_group_size();
        gs.push_back(g);
        while (g < N){
            auto c = find_cycle();
            update_As(g, c);
            sort(As.begin(), As.end(), greater<LL>());
            AAs.push_back(As);
            LL k = ks.back() + g * c;
            ks.push_back(k);
            g = find_group_size();
            gs.push_back(g);
        }
    }
    int find_group_size(){
        int g = 0;      // As[0] を下げたあと、一連の操作をして、再びAs[0]を下げる番が回ってくるまでの回数。連続してAs[0]を下げるのならば1、N個すべてを下げてから順番が回ってくるならN
        while (g < As.size() and As[g] >= As[0] - N) ++g;
        return g;
    }
    LL find_cycle(){
        return (As[0] - As[gs.back()])/(N + 1);
    }
    void update_As(int g, LL c){
        for (auto i = 0; i != g; ++i) As[i] += (g - 1 - N) * c;
        for (auto i = g; i != N; ++i) As[i] += g * c;
    }
    LL find_K(){
        As = AAs[0];
        if (As[0] < N) return 0;
        int i = 0;
        LL c = 0;
        LL g = 0;
        if (As[0] >= 2 * N){
            while (i < AAs.size() and AAs[i][0] >= 2*N) ++i;
            --i;
            As = AAs[i];
            LL d = As[0] - 2 * N;
            g = gs[i];
            c = d / (N + 1 - g);
            update_As(g, c);
        }
        if (As[0] <= (N - 1)) return ks[i] + c * g;
        LL t = 0;
        while (true){
            auto it = max_element(As.begin(), As.end());
            if (*it < N) return ks[i] + c * g + t;
            *it -= N + 1;
            for (auto & a : As) ++a;
            ++t;
        }
    }
    void print(){
        for (int i = 0; i != ks.size(); ++i){
            cout << "k:" << ks[i] << " g:" << gs[i] << "\n As:";
            for (auto a : AAs[i]) cout << " " << a;
            cout << endl << endl;
        }
    }
};



int main() {
    int N;
    cin >> N;
    vector<LL> As(N);
    for (auto & a : As) cin >> a;
    DecreasingArray da(N, As);
    cout << da.find_K() << endl;

//    int N = 3;
//    vector<LL> As = {6, 6, 5};
//    DecreasingArray da(N, As);
//    for (int K = 0; K != 20; ++K){
//        auto v = da.do_K(K);
//        cout << K << ": " << "v: " << v << " As: ";
//        for (auto a : da.As) cout << a << " ";
//        cout << endl;
//    }
//    int N = 5;
//    int Ntest = 1000;
//    while (Ntest--){
//        cout << "Ntest = " << Ntest << endl;
//        vector<LL> As(N);
//        for (auto & a : As) a = rand() % 100;
//        DecreasingArray da(N, As);
//        DecreasingArrayNaive dn(N, As);
//        auto k = da.find_K();
//        auto ret = dn.do_K(k);
//        if (ret != k){
//            cout << "Wrong: k = " << k << ", ret != " << ret << ", As = ";
//            for (auto v : As) cout << v << " ";
//            cout << ", Asfinal = ";
//            for (auto v : dn.As) cout << v << " ";
//            cout << endl;
//            cout << endl;
//            break;
//        }
//
//    }
    return 0;
}