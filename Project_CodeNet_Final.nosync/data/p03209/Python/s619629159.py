n, x = map(int, input().split())

h = [0] * (n + 1)
h[0] = 1
for i in range(n):
    h[i + 1] = h[i] * 2 + 3

def rec(n, x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    if x * 2 > h[n]:
        return 2 ** n + rec(n - 1, x - 1 - h[n] // 2)
    return rec(n - 1, x - 1)

print(rec(n, x))