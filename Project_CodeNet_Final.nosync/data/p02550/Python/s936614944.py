N, X, M = map(int, input().split())

id_ = [-1] * M
a = []
len_ = 0
ans = 0
x = X
while id_[x] == -1:
    id_[x] = len_
    len_ += 1
    ans += x
    a.append(x)
    x = x**2 % M

c = len_ - id_[x]
s = 0
for i in range(id_[x], len_):
    s += a[i]

if len_ >= N:
    ans = 0
    for i in range(N):
        ans += a[i]
else:
    n = N
    n -= len_
    ans += s * (n // c)
    n %= c
    for i in range(n):
        ans += a[id_[x]+i]
print(ans)