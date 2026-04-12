N, X = map(int, input().split())
c = [1] * (N + 1)
p = [1] * (N + 1)
for i in range(1, N + 1):
    c[i] = c[i - 1] * 2 + 3
    p[i] = p[i - 1] * 2 + 1
def solve(l, x):
    if l == 0:
        return x
    res = 0
    x -= 1
    if x <= 0: return res
    if x < c[l - 1]:
        res += solve(l - 1, x)
    else:
        res += p[l - 1]
        x -= c[l - 1]
        if x >= 1:
            res += 1
            x -= 1
        if x <= 0: return res
        if x < c[l - 1]:
            res += solve(l - 1, x)
        else:
            res += p[l - 1]
    return res
print(solve(N, X))
