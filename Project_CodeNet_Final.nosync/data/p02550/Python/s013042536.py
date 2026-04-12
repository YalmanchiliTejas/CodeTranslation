n, x, m = map(int, input().split())
a = x
dup = [0]*(10**5+10)
mod = [a]
loop = []
cnt = 0
while cnt < n:
    a = a**2 % m
    if dup[a]==1:
        i = mod.index(a)
        before = mod[:i]
        loop = mod[i:]
        break
    mod.append(a)
    dup[a] = 1
    cnt += 1

length = len(loop)
if length == 0:
    print(sum(mod[:n]))
else:
    t = (n-i)//length
    amari = (n-i) % length
    ans = sum(before) + t * sum(loop) + sum(loop[:amari])
    print(ans)
