#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

template<class T> class SegTree
{
    private:
        int _n;
        int _d;

        template<class U> class SNode
        {
            public:
                U _min;
                U _max;
                U _sum;
                U _value;
                U _add;
                U _mul;
                bool _used;
                bool _last;

                SNode()
                {
                    _min = 0;
                    _max = 0;
                    _sum = 0;
                    _value = 0;
                    _add = 0;
                    _mul = 1;
                    _used = false;
                    _last = false;
                }

                SNode(const SNode<U> &t)
                {
                    set(t);
                }

                void set(const SNode<U> &t)
                {
                    _min = t._min;
                    _max = t._max;
                    _sum = t._sum;
                    _value = t._value;
                    _add = t._add;
                    _mul = t._mul;
                    _used = t._used;
                    _last = t._last;
                }

                void set(U v)
                {
                    _min = v;
                    _max = v;
                    _sum = v;
                    _value = v;
                    _add = 0;
                    _mul = 1;
                    _last = true;
                    _used = true;
                }

                void set(U v, int d)
                {
                    _min = v;
                    _max = v;
                    _sum = v * (1 << d);
                    _value = v;
                    _add = 0;
                    _mul = 1;
                    _last = true;
                    _used = true;
                }                
        };

        SNode<T>* nodes;

        int dindex(int d)
        {
            return (1 << d);
        }

        T calcvalue(int index, T v, int num = 1) { 
            T ret = v * nodes[index]._mul + nodes[index]._add * num;
            return ret;
        }
        T getnodemin(int index) { return calcvalue(index, nodes[index]._mul < 0 ? nodes[index]._max : nodes[index]._min);  }
        T getnodemax(int index) { return calcvalue(index, nodes[index]._mul >= 0 ? nodes[index]._max : nodes[index]._min);  }
        T getnodesum(int index, int d) { return calcvalue(index, nodes[index]._sum, 1 << (_d - 1 - d));  }
        T getvalue(int index) { return calcvalue(index, nodes[index]._value);  }

        void evalnode(int index, int d)
        {
            if( index < 1 ) return;
            nodes[index]._used = true;
            if( d == _d - 1 )
            {
                 nodes[index]._min =  getvalue(index);
                 nodes[index]._max =  getvalue(index);
                 nodes[index]._sum =  getvalue(index);
            }
            else if( nodes[index * 2]._used && nodes[index * 2 + 1]._used )
            {
                nodes[index]._min = min(getnodemin(2 * index), getnodemin(2 * index + 1));
                nodes[index]._max = max(getnodemax(2 * index), getnodemax(2 * index + 1));
                nodes[index]._sum = getnodesum(2 * index, d + 1) + getnodesum(2 * index + 1, d + 1);
            }
            else if( nodes[index * 2]._used ) 
            { 
                nodes[index]._min = getnodemin(2 * index);
                nodes[index]._max = getnodemax(2 * index);
                nodes[index]._sum = getnodesum(2 * index, d + 1);
            }
            else if( nodes[index * 2 + 1]._used ) 
            { 
                nodes[index]._min = getnodemin(2 * index + 1);
                nodes[index]._max = getnodemax(2 * index + 1);
                nodes[index]._sum = getnodesum(2 * index + 1, d + 1);
            }
        }

        // 対象ノードが範囲に含まれるか　-1: 含まれない、　0:部分的に含まれる、1:完全に含む
        int check(int l, int r, int index, int d)
        {
            int i = index - (1 << d);
            int k = ( 1 << ( _d - d - 1) );
            if( r <= i * k || l >= (i + 1) * k ) return -1;
            if( l <= i * k && r >= (i + 1) * k ) return 1;
            return 0;
        }

        T getsub_minmax(int l, int r, int index, int d, T m)
        {
            if( m >= 0 )
            {
                if( check(l, r, index * 2, d + 1) == -1 ) return getmaxsub(l, r, 2 * index + 1, d + 1);
                if( check(l, r, index * 2 + 1, d + 1) == -1 ) return getmaxsub(l, r, 2 * index, d + 1);
                return max(getmaxsub(l, r, 2 * index, d + 1), getmaxsub(l, r, 2 * index + 1, d + 1));
            }
            else
            {
                if( check(l, r, index * 2, d + 1) == -1 ) return getminsub(l, r, 2 * index + 1, d + 1);
                if( check(l, r, index * 2 + 1, d + 1) == -1 ) return getminsub(l, r, 2 * index, d + 1);
                return min(getminsub(l, r, 2 * index, d + 1), getminsub(l, r, 2 * index + 1, d + 1));            
            }
        }

        T getminsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 || nodes[index]._last ) return getnodemin(index);
            if( check(l, r, index, d) == 1 ) return getnodemin(index);
            T ret = calcvalue(index, getsub_minmax(l, r, index, d, -nodes[index]._mul));
            return ret;
        }

        T getmaxsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 || nodes[index]._last ) return getnodemax(index);
            if( check(l, r, index, d) == 1 ) return getnodemax(index);
            T ret = calcvalue(index, getsub_minmax(l, r, index, d, nodes[index]._mul));
            return ret;
        }

        T getsumsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 ) return getnodesum(index, d);
            int i = index - (1 << d);
            int k = ( 1 << ( _d - d - 1) );
            if( nodes[index]._last ) return (min(r, (i + 1) * k) - max(l, i * k)) * calcvalue(index, nodes[index]._value);
            if( check(l, r, index, d) == 1 ) return getnodesum(index, d);
            T ret = 0;
            int n1 = min(r, i * k + k / 2 ) - max( l, i * k);
            int n2 = min(r, i * k + k) - max( l, i * k + k / 2);
            if( n1 > 0 ) ret += calcvalue(index, getsumsub(l, r, 2 * index, d + 1), n1);
            if( n2 > 0 ) ret += calcvalue(index, getsumsub(l, r, 2 * index + 1, d + 1), n2);
            return ret;
        }

        void denpan(int index, int d)
        {
            nodes[index]._last = false;
            T pre = getvalue(index);
            setRangeSub(0, _n, index * 2, d + 1, pre);
            setRangeSub(0, _n, index * 2 + 1, d + 1, pre);
            nodes[index]._add = 0;
            nodes[index]._mul = 1;
        }

        void calcdenpan(int index, int d)
        {
            T premul = nodes[index]._mul;
            T preadd = nodes[index]._add;
            if( premul != 1 )
            {
                mulRangeSub(0, _n, index * 2, d + 1, premul);
                mulRangeSub(0, _n, index * 2 + 1, d + 1, premul);
            }
            if( preadd != 0 )
            {
                addRangeSub(0, _n, index * 2, d + 1, preadd);
                addRangeSub(0, _n, index * 2 + 1, d + 1, preadd);
            }
            nodes[index]._mul = 1;
            nodes[index]._add = 0;
        }

        void setRangeSub(int l, int r, int index, int d, T v)
        {
            if( d == _d - 1 || check(l, r, index, d) == 1 ) { nodes[index].set(v, _d - 1 - d); return; }
            if( nodes[index]._last ) denpan(index, d);
            calcdenpan(index, d);
            if( check(l, r, index * 2, d + 1) != -1 ) setRangeSub(l, r, index * 2, d + 1, v);
            if( check(l, r, index * 2 + 1, d + 1) != -1 ) setRangeSub(l, r, index * 2 + 1, d + 1, v);
            evalnode(index, d);
        }

        void addRangeSub(int l, int r, int index, int d, T v)
        {
            if( d == _d - 1 || check(l, r, index, d) == 1 ) { nodes[index]._add += v; return; }
            if( nodes[index]._last ) denpan(index, d);
            if( nodes[index]._mul != 1 ) calcdenpan(index, d);
            if( check(l, r, index * 2, d + 1) != -1 ) addRangeSub(l, r, index * 2, d + 1, v);
            if( check(l, r, index * 2 + 1, d + 1) != -1 ) addRangeSub(l, r, index * 2 + 1, d + 1, v);
            evalnode(index, d);
        }

        void mulRangeSub(int l, int r, int index, int d, T v)
        {
            if( d == _d - 1 || check(l, r, index, d) == 1 ) { 
                nodes[index]._mul *= v; 
                nodes[index]._add *= v;
                return; 
            }            
            if( nodes[index]._last ) denpan(index, d);
            if( nodes[index]._add != 0 ) calcdenpan(index, d);
            if( check(l, r, index * 2, d + 1) != -1 ) mulRangeSub(l, r, index * 2, d + 1, v );
            if( check(l, r, index * 2 + 1, d + 1) != -1 ) mulRangeSub(l, r, index * 2 + 1, d + 1, v);
            evalnode(index, d);
        }

        T getSub(int i, int index, int d)
        {
            if( d == _d - 1 || nodes[index]._last || !nodes[index]._used) return getvalue(index);
            if( check(i, i + 1, index * 2, d + 1) != -1 ) return calcvalue(index, getSub(i, 2 * index, d + 1));
            return calcvalue(index, getSub(i, 2 * index + 1, d + 1));
        }        


    public:
        SegTree(int n)
        {
            _n = n;
            _d = 1;
            int bit = 1;
            while( bit < _n )
            {
                bit *= 2;
                _d++;
            }
            nodes = new SNode<T>[bit * 2];
            for(int i = 0; i < n; i++ ) nodes[bit + i]._used = true;
            for(int i = bit - 1; i >= 0; i-- ) nodes[i]._used = (nodes[i * 2]._used || nodes[i * 2 + 1]._used);
        }

        ~SegTree()
        {
            delete nodes;
        }

        void set(int i, T value) { setRangeSub(i, i + 1, 1, 0, value); }

        T get(int i) { return getSub(i, 1, 0); }

        // l <= i < r
        void setRange(int l, int r, T value)
        {
            setRangeSub(l, r, 1, 0, value);
        }

        void addRange(int l, int r, T value)
        {
            addRangeSub(l, r, 1, 0, value);
        }

        void mulRange(int l, int r, T value)
        {
            mulRangeSub(l, r, 1, 0, value);
        }

        T getmin(int l, int r)
        {
            return getminsub(l, r, 1, 0);
        }

        T getmax(int l, int r)
        {
            return getmaxsub(l, r, 1, 0);
        }

        T getsum(int l, int r)
        {
            return getsumsub(l, r, 1, 0);
        }
};


int get3(SegTree<int> &st, int x, int v, int n)
{
    int l = x;
    int r = n;
    if( st.getmax(x, n) < v ) return n;

    while( l < r )
    {
        int m = (l + r) / 2;
        if( st.getmax(x, m + 1) >= v )
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int main()
{
    int n, q; cin >> n >> q;
    SegTree<int> st(n);
    rep(i, n) { int a; cin >> a; st.set(i, a); }
    rep(j, q)
    {
        int t, a, b; cin >> t >> a >> b;
        switch(t)
        {
            case 1:
                st.set(a - 1, b);
                break;
            case 2:
                cout << st.getmax(a - 1, b) << endl;
                break;
            case 3:
                cout << get3(st, a - 1, b, n) + 1 << endl;
                break;
        }
    }
    return 0;
}