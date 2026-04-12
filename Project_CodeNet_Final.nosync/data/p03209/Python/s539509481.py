N, X = map(int, input().split())
a = [1] * (N+1)
p = [1] * (N+1)
for i in range(1,N+1):
    a[i] = a[i-1]*2 + 3
    p[i] = p[i-1]*2 + 1
def f(n, x):
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif 2<= x <= a[n-1] + 1:
        return f(n-1, x-1)
    elif x == a[n-1] + 2:
        return p[n-1] + 1
    elif a[n-1]+3 <= x <= 2*a[n-1]+2:
        return p[n-1]+1+ f(n-1, x-(a[n-1]+2))
    elif x == 2*a[n-1]+3:
        return p[n]
print(f(N,X))