N, X = map(int, input().split())
a, p = [1], [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def paty(L, n):
    if L == 0:
        return 0 if n <= 0 else 1
    elif n <= 1 + a[L - 1]:
        return paty(L-1, n-1)
    else:
        return p[L-1] + 1 + paty(L-1, n-2-a[L-1])

print(paty(N, X))
