N,X =  map(int, input().split())
a = [1 for i in range(N)]
p = [1 for i in range(N)]
for i in range(1,N):
    a[i] = a[i-1]*2 + 3
    p[i] = p[i-1]*2 + 1
def f(N,X):
    if N <= 0:
        if X <= 0:
            return 0
        else:
            return 1
    elif X <= 1 + a[N-1]:
        return f(N-1,X-1)
    else:
        return p[N-1] + 1 + f(N-1,X-a[N-1]-2)
print(f(N,X))