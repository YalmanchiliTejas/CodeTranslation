def rec(L, X):
    S = [0 for i in range(51)]
    S[0] = 1
    for i in range(1, 51):
        S[i] = 3 + 2 * S[i - 1]
    dic = {}
    def f(L, X):
        if L == 0:
            return 1
        if X < 2:
            return 0
        if (L, X) in dic:
            return dic[(L, X)]
        if X < S[L - 1] + 1:
            dic[(L, X)] = f(L - 1, X - 1)
        elif X == S[L - 1] + 1:
            dic[(L, X)] = f(L - 1, S[L - 1])
        elif X == S[L - 1] + 2:
            dic[(L, X)] = f(L - 1, S[L - 1]) + 1
        else:
            dic[(L, X)] = f(L - 1, S[L - 1]) + 1 + f(L - 1, X - 2 - S[L - 1])
        return dic[(L, X)]
    return f(L, X)

L, X = map(int, input().split())
print(rec(L, X))