n,x,m = map(int,input().split())
p = [0 for i in range(m)]
p[x] = 1
k = x
ans = 0
ans += k
me = [k]
mem = [k]
fin = 0
for i in range(n-1):
    k = k**2%m
    if p[k] == 0:
        p[k] = i+2
        ans += k
        mem.append(k)
        me.append(ans)
    else:
        sp = k
        ss = i+2
        fin = 1
        break
if fin == 0:
    print(ans)
else:
    for i in range(m):
        if mem[i] == sp:
            spi = i+1
            break
    if spi == 1:
        ans0 = 0
    else:
        ans0 = me[spi-2]
    uu = ans - ans0
    ans0 += ((n-spi+1)//(ss-spi))*uu
    for i in range((n-spi+1)%(ss-spi)):
        ans0 += mem[spi+i-1]
    print(ans0)