N, X = list(map(int, input().split()))

a = [2**(n+2)-3 for n in range(51)]
b = [2**(n+1)-1 for n in range(51)]

def func(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    if 2 <= x < 2+a[n-1]:
        return func(n-1, x-1)
    if x == 2+a[n-1]:
        return 1+b[n-1]
    if 3+a[n-1] <= x < 3+2*a[n-1]:
        return 1+b[n-1]+func(n-1, x-(2+a[n-1]))
    else:
        return 1+2*b[n-1]

print(func(N, X))
