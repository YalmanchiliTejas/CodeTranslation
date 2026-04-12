n,x,m = map(int,input().split())

check = set()
hazimari = -1
owari = 0
y = x

check.add(x)
for i in range(n-1):
    owari = y
    y = y**2 % m
    if y in check:
        hazimari = y
        break
    check.add(y)

if hazimari == -1:#ループするまでもなくnが小さかったとき
    print(sum(check))
    exit()

ans = 0
count = 0
lp = []
y = x
for i in range(n-1):
    ans += y
    y = y**2 % m
    count = i+1
    if y == hazimari:
        lp.append(y)
        for j in range(n):
            y = y**2 % m
            lp.append(y)
            if y == owari:
                break
    else:
        continue
    break

ans += (n-count)//len(lp) * sum(lp)
ans += sum(lp[:(n-count)%len(lp)])
print(ans)