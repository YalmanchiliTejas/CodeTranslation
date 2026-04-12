n, x, mod = [int(i) for i in input().split()]
ans = x
tmp = x
s = set()
s.add(x)
for i in range(1, n):
    tmp = (tmp * tmp) % mod
    if tmp in s:
        cycle = [tmp]
        t = (tmp * tmp) % mod
        while t != tmp:
            cycle.append(t)
            t = (t * t) % mod
        ans += sum(cycle) * ((n - i) // len(cycle))
        ans += sum(cycle[:(n-i)%len(cycle)])
        break
    else:
        s.add(tmp)
        ans += tmp
print(ans)