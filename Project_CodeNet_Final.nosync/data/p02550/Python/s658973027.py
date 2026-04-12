n, x, m = map(int, input().split())
L = []
used = set()
while x not in used:
    used.add(x)
    L.append(x)
    x = x*x%m
cnt = 0
while L[cnt] != x:
    cnt += 1
l = len(L)
if n <= l:
    print(sum(L[:n]))
    exit()
s = sum(L)
t = sum(L[cnt:])
q, r = divmod(n-l, l-cnt)
ans = s + q*t
for i in range(r):
    ans += L[cnt]
    cnt += 1
print(ans)