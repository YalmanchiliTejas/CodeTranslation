n, x = map(int, input().split())

def make_burger(i, x):
    if i == 0:
        return 1 if x >= 1 else 0
    center_num = (a[i] + 1) // 2
    if center_num > x:
        return make_burger(i - 1, x - 1)
    elif center_num == x:
        return p[i - 1] + 1
    else:
        return p[i - 1] + 1 + make_burger(i - 1, x - center_num)


a = [1]
p = [1]
for i in range(1, n + 1):
    a.append(2 * a[-1] + 3)
    p.append(2 * p[-1] + 1)

print(make_burger(n, x))