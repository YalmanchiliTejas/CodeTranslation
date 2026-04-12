def burger(n, x):
    if x < 1:
        return 0

    # base case
    if (n, x) == (0, 1):
        return 1

    if x <= 1 + size[n - 1]:
        return burger(n - 1, x - 1)
    else:
        return p_num[n - 1] + 1 + burger(n - 1, min(x - 2 - size[n - 1], size[n - 1]))
    # x-2-sizeだと前lvバーガー+バンのことがあり、バンを外す


n, x = map(int, input().split())
size, p_num = [1], [1]
for i in range(1, 50 + 1):
    size.append(size[-1] * 2 + 3)
    p_num.append(p_num[-1] * 2 + 1)

print(burger(n, x))
