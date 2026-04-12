def solve(n, x):
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0
    elif 1 < x < layer[n] // 2 + 1:
        return solve(n-1, x-1)
    elif x == layer[n] // 2 + 1:
        return patty[n-1] + 1
    elif layer[n] // 2 + 1 < x < layer[n]:
        return solve(n-1, x-layer[n-1]-2) + patty[n-1] + 1
    else:
        return patty[n]


N, X = map(int, input().split())

layer, patty = [1], [1]
for _ in range(N):
    layer.append(layer[-1] * 2 + 3)
    patty.append(patty[-1] * 2 + 1)

print(solve(N, X))