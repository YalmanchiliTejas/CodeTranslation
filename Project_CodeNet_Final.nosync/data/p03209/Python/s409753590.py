N, K = map(int, input().split())

c = [1, 1]
t = [c]
for i in range(N):
    c = [c[0] * 2 + 3, c[1] * 2 + 1]
    t.append(c)

def f(cur, n, k):
    u = t[n-1]
    m = u[0] + 2
    if k == t[n][0]:
        return cur + t[n][1]
    elif k == 1:
        return cur
    elif k == m:
        return cur + 1 + u[1]
    elif k > m:
        return f(cur + 1 + u[1], n - 1, k - u[0] - 2)
    elif m > k:
        return f(cur, n - 1, k - 1)
print(f(0, N, K))