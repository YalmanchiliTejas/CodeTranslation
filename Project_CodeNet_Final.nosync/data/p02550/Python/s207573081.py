N, X, M = map(int, input().split())
d = dict()
L = []
for i in range(M+1):
    if X not in d:
        d[X] = i
        L.append(X)
    else:
        j = d[X]
        k = i
        break
    X = X*X%M
s=k-j
kk, zz = divmod((N-j), s)
print(sum(L[:j])+sum(L[j:])*kk+sum(L[j:j+zz]))

