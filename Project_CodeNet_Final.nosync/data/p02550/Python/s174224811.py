N, X, M = map(int, input().split())

id = [-1] * M
a = []
l = 0
tot = 0
while id[X] == -1:
    a.append(X)
    id[X] = l
    l += 1
    tot += X
    X = X ** 2 % M

c = l - id[X]
s = 0
for i in range(id[X], l):
    s += a[i]

ans = 0
if N <= l:
    for i in range(N):
        ans += a[i]
else:
    ans += tot
    N -= l
    ans += s * (N // c)
    N %= c
    for i in range(N):
        ans += a[id[X] + i]

print(ans)
