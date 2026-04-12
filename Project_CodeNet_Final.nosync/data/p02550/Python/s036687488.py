n, x, m = map(int, input().split())

cnt = [x]
c = set()
c.add(x)

for i in range(m+1):
    x = x*x % m
    if x in c:
        break
    cnt.append(x)
    c.add(x)

start = cnt.index(x)

ans = sum(cnt[:start])
roop = len(cnt) - start

n = n-start
ans = ans + (n//roop)*sum(cnt[start:]) + sum(list(cnt)[start:(start+n%roop)])

print(ans)