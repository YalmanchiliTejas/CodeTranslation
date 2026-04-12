N, S = map(int, input().split())
A = list(map(int, input().split()))
#d = sum(A)
mod = 998244353

"""
多項式係数を使った数え上げでリベンジしてみる。
maspyさんのを参考に実装する。

（注意）多項式係数全てを書き下すと、d = sum(A)次式になるが、
これは Ai*N = 3000*3000 次になりTLEする。。。
S次の項までで打ち切る事を忘れない事。

やってみてわかったけど、実装自体はdpでやったのとほぼ同じ。
多項式係数を使う方法は実質flexibleなdpということ？
"""

f = [0] * (1 + S) # f[i] = (coefficient of degree i)
ans = 0

for i in range(N):
    g = [0] * (1 + S) # g = (1 + f) * (1 + x^{A[i]})
    f[0] += 1
    for j in range(1 + S):
        if j - A[i] < 0:
            g[j] = f[j]
        else:
            g[j] = f[j] + f[j - A[i]]
    ans += g[S]
    ans %= mod
    f = g

print(ans)
