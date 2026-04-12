N = int(input())
A = [int(input()) for i in range(N)]

A_ = sorted(A)
A_r = list(reversed(A_))

l = []
for i, (x, y) in enumerate(zip(A_[:N//2], A_r[:N//2])):
    if i % 2 == 0:
        l.append(x)
        l.insert(0, y)
    else:
        l.append(y)
        l.insert(0, x)

if N % 2 != 0:
    m = A_[N//2]
    if abs(l[0] - m) > abs(l[-1] - m):
        l.insert(0, m)
    else:
        l.append(m)

def g(L):
    for i, j in zip(L[:-1], L[1:]):
        yield abs(i - j)

print(sum(g(l)))
