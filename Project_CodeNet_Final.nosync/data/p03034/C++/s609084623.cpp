#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = (i64)1e9 + 7;

const i64 INF = (i64)1e18 + 7;


template <typename T = i64>
struct Range{
    struct iterator{
        T value;
        const T step, last;
        const T& operator*(){return value;}
        iterator(T value, T step, T last) :
            value(step < static_cast<T>(0) ? max(last, value) : min(last, value)),
            step(step),
            last(last)
        {
        }
        iterator operator++(){value = step < static_cast<T>(0) ? max(value + step, last) : min(value + step, last); return *this;}
        bool operator!=(const iterator& x){return value != x.value;}
    };
    const T start, last, step;

    Range(const T start, const T last, const T step = static_cast<T>(1)) :
        start(start),
        last(last),
        step(step)
    {
    }

    Range(const T last) :
        start(0),
        last(last),
        step(1)
    {
    }

    iterator begin(){return iterator(start, step, last);}
    iterator end(){return iterator(last, step, last);}
};

template <typename F>
struct FixPoint{
    const F _f;
    FixPoint(F&& f) : _f(forward<F>(f)){}

    template<typename... Types>
    decltype(auto) operator()(Types&&... args) const{
        return _f(*this, forward<Types>(args)...);
    }
};

template <typename F>
static decltype(auto) makeRec(F&& f){
    return FixPoint<F>(forward<F>(f));
}

template <typename T, T Value = T()>
vector<T> makeVector(size_t x){
    return vector<T>(x, T(Value));
}

template <typename T, T Value = T(), typename... Types>
auto makeVector(size_t x, Types... args){
    return vector<decltype(makeVector<T, Value>(args...))>(x, makeVector<T, Value>(args...));
}

template <typename T = i64>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template <typename T = i64>
bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

#ifdef TEST
#define dump(x) fprintf(stderr, "line =%4d, name =%7s , ", __LINE__, #x); cout << "value = " << x << endl;
#define vecdump(x) fprintf(stderr, "line =%4d, name =%7s\n", __LINE__, #x); _dump_macro(x);
#else
#define vecdump(x)
#define dump(x)
#endif


void _dump(int, string& x){
#ifdef TEST
    cout << x << endl;
#endif
}

template <typename T>
void _dump(bool, T& x){
#ifdef TEST
    cout << x << " ";
#endif
}

template <typename T, typename U = typename T::iterator>
void _dump(int, T& x){
#ifdef TEST
    for(auto& elm : x)
        _dump(0, elm);

    cout << endl;
#endif
}

template <typename T>
void _dump_macro(T& x){
    _dump(0, x);
}

void _input(int, string& x){
    cin >> x;
}

template <typename T>
void _input(bool, T& x){
    cin >> x;
}

template <typename T, typename U = typename T::iterator>
void _input(int, T& x){

    for(auto& elm : x)
        _input(0, elm);
}

template <typename T>
void input_single(T& x){
    _input(0, x);
}

auto input(){}

template <typename T, typename... Types>
void input(T& value, Types&&... args){
    input_single(value);
    input(forward<Types>(args)...);
};

void _pararell_input(size_t){}

template <typename T, typename... Types>
void _pararell_input(size_t index, T& value, Types&&... args){
    input(value[index]);
    _pararell_input(index, forward<Types>(args)...);
}

template <typename... Types>
void pararell_input(size_t count, Types&&... args){
    for(const auto& i : Range<>(count))
        _pararell_input(i, forward<Types>(args)...);
}


int solve(int _count){

    int n = 0;
    input(n);
    vector<int> v(n);
    input(v);

    if(!static_cast<bool>(cin))
        return MOD;
#ifdef TEST
    cout << "Case: " << _count << endl;
#endif

    i64 ans = -INF;
    for(int d = 1; d <= n - 1; ++d){
        int k = (n - 1) % d;
        int a = k;
        unordered_set<int> p, q, w;
        i64 sum = 0;
        for(int t = a; t != n - 1; t += d){
            p.emplace(t);
            sum += v[t];
        }
        for(int t = d; t != n - 1 - a; t += d){
            q.emplace(t);
            sum += v[t];
            if(p.find(t) != p.end())
                w.emplace(t);
        }
        for(int m = 1; n - 1 - m * d >= 0; ++m){
            if(p.find(a) != p.end()){
                p.erase(a);
                sum -= v[a];
                if(w.find(a) != w.end())
                    w.erase(a);
            }
            if(q.find(n - 1 - a) != q.end()){
                sum -= v[n - 1 - a];
                q.erase(n - 1 - a);
                if(w.find(n - 1 - a) != w.end())
                    w.erase(n - 1 - a);
            }
            a += d;
            if(w.empty())
                chmax(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}


signed main(){

    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t = 0;
    while(solve(++t) != MOD);
}
