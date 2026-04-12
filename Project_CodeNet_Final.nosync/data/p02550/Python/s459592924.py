N,X,M = map(int,input().split())
c1 = [X]
c2 = {X}
ans = X
for i in range(N-1):
    X = pow(X,2,M)
#    print(X)
    if X not in c2:
        c1.append(X)
        c2.add(X)
        ans += X
    else:
        b = c1.index(X)
        break
else:
    print(ans)
    exit()
l = len(c1) - b
t = N-i -1
ans += (t//l) * sum(c1[b:]) + sum(c1[b:b+t%l])
print(ans)