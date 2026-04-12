def d_christmas(N, X):
    # レベルnのときのパティの総数をp_nと書くと、 p_{n+1} = p_n + 1 + p_n, p_0 = 1
    # レベルnのときのバーガーの層数をa_nと書くと、 a_{n+1} = 1 + a_n + 1 + a_n + 1, a_0 = 1
    a, p = [1], [1]
    for _ in range(N):
        a.append(a[-1] * 2 + 3)
        p.append(p[-1] * 2 + 1)

    def f(n, x):
        # レベルnバーガーの下からn層食べたとき、食べたパティの数
        if n == 0:
            return 0 if x <= 0 else 1  # パティが1枚だけのバーガーを食べる
        elif x <= 1 + a[n - 1]:
            return f(n - 1, x - 1)
        else:
            return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1])

    return f(N, X)

N, X = [int(i) for i in input().split()]
print(d_christmas(N, X))