
n, x = map(int, input().split())

a, p = [1], [1]

for i in range(n):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def cnt_p(n, x):
    if n == 0:
        if x <= 0:
            return 0
        return 1
    elif x <= 1 + a[n - 1]:
        return cnt_p(n - 1, x - 1)
    else:
        return p[n - 1] + 1 + cnt_p(n - 1, x - 2 - a[n - 1])


print(cnt_p(n, x))