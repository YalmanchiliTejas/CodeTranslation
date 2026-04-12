n, x, m = map(int, input().split())
ans = [x]
for _ in range(m):
    ans.append(pow(ans[-1], 2, m))
loop = [ans[-1]]
check = ans[-1]
for _ in range(m):
    next = pow(loop[-1], 2, m)
    if next == check:
        break
    else:
        loop.append(next)
if n <= m+1:
    A = sum(ans[:n])
else:
    times = (n - m) // len(loop)
    amari = (n - m) % len(loop)
    A = sum(ans[:-1]) + sum(loop) * times + sum(loop[:amari])
print(A)