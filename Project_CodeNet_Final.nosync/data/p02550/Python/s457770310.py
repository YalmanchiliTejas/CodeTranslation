N, X, M = map(int,input().split())
i = X % M
L = [i]
S = set([i])
i = i ** 2 % M
while not i in S:
    L.append(i)
    S.add(i)
    i = i ** 2 % M
index = L.index(i)
k = (N - index) // len(L[index:])
l = (N - index) % len(L[index:])

ans = sum(L[:index]) + (k * sum(L[index:]) + sum(L[index:index + l]))
print(ans)