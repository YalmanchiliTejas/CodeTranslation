n, x = map(int, input().split())
L = [[1, 1]]
for i in range(1, n+1):
    L.append([L[i-1][0] * 2 + 3, L[i-1][1] * 2 + 1])
def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + L[n-1][0]:
        return f(n-1, x-1)
    else:
        return L[n-1][1] + 1 + f(n-1, x-2-L[n-1][0])
print(f(n, x))
