N,X,M = map(int,input().split())

order = []
hist = [0] * M

for i in range(N):
    if hist[X]:
        j = order.index(X)
        rem = N-i
        d,m = divmod(rem,i-j)
        for k in order[j:]:
            hist[k] += d
        for k in order[j:j+m]:
            hist[k] += 1
        break
    order.append(X)
    hist[X] += 1
    X = (X*X)%M

ans = 0
for i,h in enumerate(hist):
    ans += i*h
print(ans)