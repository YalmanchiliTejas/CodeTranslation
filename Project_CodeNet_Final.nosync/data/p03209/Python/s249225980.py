N, X = map(int,input().split())
def dfs(L, X):
    if X == 1:
        if L == 0:
            return 1
        else:
            return 0
    elif 2 <= X <= 2 ** (L + 1) - 2:
        return dfs(L - 1, X - 1)
    elif X == 2 ** (L + 1) - 1:
        return 2 ** L
    elif 2 ** (L + 1) <= X <= 2 ** (L + 2) - 4:
        return 2 ** L + dfs(L-1, X - 2 ** (L + 1) + 1)
    else:
        return 2 ** (L + 1) - 1
print(dfs(N, X))