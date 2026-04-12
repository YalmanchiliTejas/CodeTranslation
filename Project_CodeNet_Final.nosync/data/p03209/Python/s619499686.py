n, x = map(int, input().split())
a = [0]*(n+1)
p = [0]*(n+1)
a[0] = 1
p[0] = 1
for i in range(n):
    a[i+1] = 2*a[i]+3
    p[i+1] = 2*p[i]+1


def paty(n, x):
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif 1 < x <= 1+a[n-1]:
        return paty(n-1, x-1)
    elif x == 2+a[n-1]:
        return p[n-1]+1
    elif 2+a[n-1] < x <= 2+2*a[n-1]:
        return p[n-1]+1+paty(n-1, x-2-a[n-1])
    elif x == 3+2*a[n-1]:
        return 2*p[n-1]+1


print(paty(n, x))
