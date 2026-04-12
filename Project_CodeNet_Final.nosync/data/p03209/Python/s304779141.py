N, X = map(int, input().split())

size, p_num = [1], [1]
for i in range(1, N + 1):
    size.append(size[i - 1] * 2 + 3)
    p_num.append(p_num[i - 1] * 2 + 1)


def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + size[n - 1]:
        return f(n - 1, x - 1)
    else:
        return p_num[n - 1] + 1 + f(n - 1, x - 2 - size[n - 1])  # x - 1 - size[n - 1] - 1


print(f(N, X))
