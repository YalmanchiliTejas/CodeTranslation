n, x, m = map(int, input().split())
a = [x]
if n == 1:
    print(x)
    exit()
for i in range(n-1):
    ad = (a[-1]**2) % m
    if ad in a:
        roop_s = a.index(ad)
        roop_e = len(a)
        break
    else:
        a.append(ad)
    if i == n-2:
        print(sum(a))
        exit()
roop_t = (n-roop_s) // (roop_e - roop_s)
left = n - roop_t*(roop_e - roop_s) - roop_s
ans = sum(a[:roop_s]) + roop_t*sum(a[roop_s : roop_e]) + sum(a[roop_s:roop_s+left])
print(ans)