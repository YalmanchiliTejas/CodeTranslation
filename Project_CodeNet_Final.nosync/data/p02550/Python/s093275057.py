from collections import defaultdict
n, x, m = map(int, input().split())
now = x
ans = x
d = defaultdict(int)
repeat = []

for i in range(n):
    now = (now**2)%m
    d[now] += 1
    repeat.append(now)
    if d[now] > 1:
        break

for g in range(len(repeat)):
    if repeat[g] == now:
        break
    else:
        ans += repeat[g]
        n -= 1

repeat = repeat[g:-1] 
n -= 1
if len(repeat) != 0:
    ans += sum(repeat)*(n//len(repeat)) + sum(repeat[:n%len(repeat)])
print(ans)
