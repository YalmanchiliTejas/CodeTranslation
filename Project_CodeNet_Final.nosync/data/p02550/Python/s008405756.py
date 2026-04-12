n, x, m = map(int, input().split())

ans = 0
a = [0]
id = [0]*(m+1)
l = 1
while id[x] == 0:
    a.append(x)
    id[x] = l
    ans += x
    l += 1
    x = x**2 % m

c = l - id[x]
s=0

for i in range(id[x],l):
    s += a[i]

if n <= l-1:
    ans = 0
    for i in range(1,n+1):
        ans += a[i]
else:
    n -= l
    n += 1
    ans += s*(n//c)
    n %= c
    for i in range(n):
        ans += a[id[x] + i]
print(ans)