def solve(n, x):
    layers = 2 ** (n + 1) - 3  # レベルn-1バーガーの層の数
    patties = 2 ** n - 1    # レベルn-1バーガーのパティの数
    if x == 0:
        ans = 0
    elif x <= layers + 1:
        ans = solve(n - 1, x - 1)
    elif x <= 2 * layers + 2:
        ans = patties + 1 + solve(n - 1, x - layers - 2)
    else:
        ans = 2 * patties + 1

    return ans

N, X = [int(x) for x in input().split()]
print(solve(N, X))