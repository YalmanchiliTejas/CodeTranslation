N,X = map(int,input().split())
# a:バンの数  b:パティの数
a,b = [1],[1]
for i in range(N):
    a.append(2*a[i] + 3)
    b.append(2*b[i] + 1)
def f(N,X):
    if N == 0:
        return 1
    if X == 1:
        return 0
    elif 1 < X <= a[N-1] + 1:
        return f(N-1,X-1)
    elif X == a[N-1] + 2:
        return b[N-1] + 1
    elif a[N-1] + 2 < X <= 2*a[N-1] + 2:
        return b[N-1] + 1 + f(N-1,X-(a[N-1]+2))
    elif X == 2*a[N-1] + 3:
        return 2*b[N-1] + 1
ans = f(N,X)
print(ans)