n,x,m = map(int, input().split())
ai = x
tmp = [ai]
used = set(tmp)
for i in range(n):
    nxt = ai**2 % m
    if nxt in tmp:
        break
    tmp.append(nxt)
    ai = nxt
if len(tmp) == n:
    ans = sum(tmp)
    print(ans)
    exit()

first = tmp.index(nxt)
ans = 0
l = []
for i in range(len(tmp)):
    if i < first:
        ans += tmp[i]
        n -= 1
    else:
        l.append(tmp[i])
m = len(l)
x,y = divmod(n, m)
ans += sum(l)*x
for i in range(y):
    ans += l[i]
print(ans)

