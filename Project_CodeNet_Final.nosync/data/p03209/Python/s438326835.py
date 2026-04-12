n, x = map(int, input().split())
d = [1]
for _ in range(50):
    d.append(d[-1] * 2 + 3)
ans = 0
def f(i, h):
    if h == 0:
        return 1 if i == 1 else 0
    if i == 0:
        return 0
    mid = d[h-1] + 1
    if i <= mid:
        return f(i-1, h-1)
    if i == mid + 1:
        return 2 ** h
    if i <= d[h] - 1:
        return 2 ** h + f(i-mid-1, h-1)
    else:
        return 2 ** (h + 1) - 1
print(f(x, n))
