n, x, m = map(int, input().split())
s = 0
R = [-1]*m
R[x] = 0
T = [x]
for i in range(1, m+1):
    x = (x**2)%m
    T.append(x)
    if R[x] != -1:
        r = R[x]
        q = i-R[x]
        break
    else:
        R[x] = i
#print(R)
#print(r)
#print(q)

c = 0
for i in range(q):
    c += T[r+1+i]

X = [-1]*m
for i, e in enumerate(R):
    if e == -1:
        continue
    else:
        X[e] = i

n -= 1
if n <= r:
    ans = 0
    for i in range(n+1):
        ans += X[i]
else:
    ans = 0
    for i in range(r+1):
        ans += X[i]
    n -= r
    s, t = divmod(n, q)
    for i in range(t):
        ans += T[r+1+i]
    ans += c*s
print(ans)
