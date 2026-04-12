n, x, m = map(int, input().split())
l = [x]
a = x
loopsum = 0
loopnum = 0


for i in range(n - 1):
    a = a**2%m
    if a not in l:
        l.append(a)
    else:
        pos = l.index(a)
        loopnum = len(l[pos:])
        loopsum = sum(l[pos:])
        break

if loopnum > 0:
    rest = (n - len(l))%loopnum
    times = (n - len(l))//loopnum
    ans = sum(l) + loopsum*times
    for i in range(rest):
        ans += l[pos + i]
else:
    ans = sum(l)

print(ans)