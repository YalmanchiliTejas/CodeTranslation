N, X, M = list(map(int, input().split()))
i = 1
a = X
s = 0
L = []
while i < N and a > 0:
    L.append(a)
    s += a
    a = (a**2) % M
    if a in L:
        j = L.index(a)
        break
    i += 1
else:
    s += a
    print(s)
    exit()

# print(L)
t = sum(L[:j])
L = L[j:]
u = s-t
N = N-j
v = t+u*(N//(i-j))
if N % (i-j) == 0:
    pass
else:
    v += sum(L[:N % (i-j)])
print(v)
