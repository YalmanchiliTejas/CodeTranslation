N, X, M = map(int, input().split())

d = {}
l = []
for i in range(N):
    if X in d:
        break
    d[X] = i
    l.append(X)
    X = X*X%M
else:
    print(sum(l))
    exit()

s = d[X]

q, r = divmod(N-s,i-s)
ans = sum(l[:s])+q*sum(l[s:i])+sum(l[s:s+r])
print(ans)