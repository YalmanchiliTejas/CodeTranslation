N, X = map(int, input().split())
a, p = [1], [1]

for i in range(50):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def Burger(N, X):
    if N == 0:
        return 1
    if X == 1:
        return 0
    elif 1 < X <= a[N-1]+1:
        return Burger(N-1, X-1)
    elif X == a[N-1]+2:
        return p[N-1]+1
    else:
        return p[N-1]+1+Burger(N-1, X-2-a[N-1])

print(Burger(N, X))