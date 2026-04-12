
n, x, m = list(map(int, input().split()))

s = [0, x]
d = {x: 1}
su = x
ans = x
for i in range(2, n+1):
    x = (x * x) % m
    su += x
    if x in d:
        a = su - s[d[x]]
        ans = s[d[x]] - x
        le = i - d[x]
        rep = (n - d[x] + 1) // le
        ans += a * rep
        amari = (n - d[x] + 1) % le
        for j in range(amari):
            ans += x
            x = (x * x) % m
        break
    else:
        s.append(su)
        d[x] = i
        ans = su
print(ans)