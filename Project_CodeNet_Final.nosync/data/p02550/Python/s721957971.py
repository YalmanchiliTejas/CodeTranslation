n, x, m = map(int, input().split())

f = [-1]*m
ans = x
n -= 1
while n > 0:
    if f[x] == -1:
        f[x] = pow(x, 2, m)
        ans += f[x]
        x = f[x]
        n -= 1
    else:
        break
loop = [x]
ans -= x
for i in range(n):
    tmp = pow(loop[-1], 2, m)
    if tmp == loop[0]:
        break
    loop.append(tmp)
loopsum = sum(loop)
ans += (n+1) // len(loop) * loopsum + sum(loop[0:((n+1) % len(loop))])
print(ans)
