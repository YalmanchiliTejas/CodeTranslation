def make_burger(i, x):
    if i == 0:
        return 1 if x > 0 else 0
    mid = (b[i] + 1) // 2
    if mid > x:
        return make_burger(i - 1, x - 1)
    elif mid == x:
        return p[i - 1] + 1
    else:
        return p[i - 1] + 1 + make_burger(i - 1, x - mid)
    

n, x = map(int, input().split())
p = [1]
b = [1]

for _ in range(n):
    p.append(p[-1] * 2 + 1)
    b.append(b[-1] * 2 + 3)

print(make_burger(n, x))