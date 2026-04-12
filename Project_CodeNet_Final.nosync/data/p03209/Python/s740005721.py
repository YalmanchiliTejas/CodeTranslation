N, X = map(int, input().split())

a = [2**(i+2) - 3 for i in range(N+1)]
p = [2**(i+1) - 1 for i in range(N+1)]

ans = 0

def calc(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    elif 1 < x < a[n-1]+2:
        return calc(n-1, x-1)
    elif x == 2 + a[n-1]:
        return p[n-1] + 1
    elif 2 + a[n-1] < x < 3 + 2*a[n-1]:
        return p[n-1] + 1 + calc(n-1, x-2-a[n-1])
    elif x == 3 + 2*a[n-1]:
        return 2*p[n-1] + 1


ans = calc(N, X)
print(ans)