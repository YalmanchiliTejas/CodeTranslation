k, s= map(int, input().split())
a = [1]
p = [1]
for i in range(k):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def f(n, k):
    if k == 0:
        return 1 if n==1 else 0
    elif n == 1:
        return 0
    elif 1 < n <= 1 + a[k-1]:
        return f(n-1, k-1)
    elif n == 2 + a[k-1]:
        return 1 + p[k-1]
    elif 2 + a[k-1] < n <= 2 + 2 * a[k-1]:
        return 1 + p[k-1] + f(n-2-a[k-1], k-1)
    elif n == 3 + 2 * a[k-1]:
        return 1 + 2 * p[k-1]
    else:
        return 'Err'

ans=f(s, k)
print(ans)