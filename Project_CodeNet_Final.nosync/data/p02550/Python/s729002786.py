N,X,M = map(int,input().split())
ans = X
N -= 1
divs,loop = [],[]
x = X**2%M
for _ in range(M):
    if x%M != 0:
        if x%M in divs:
            loop = divs[divs.index(x%M):]
            start = divs[:divs.index(x%M)]
            break
        else:
            divs.append(x%M)
            x = x**2
            x %= M
    else:
        start = divs
        break
if N >= len(start):
    ans += sum(start)
    if loop:
        cycle = (N-len(start))//len(loop)
        remain = (N-len(start))%len(loop)
        ans += sum(loop)*cycle + sum(loop[:remain])
else:
    ans += sum(start[:N])
print(ans)