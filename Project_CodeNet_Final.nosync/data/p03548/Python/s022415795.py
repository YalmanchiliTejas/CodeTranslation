X, Y, Z = map(int, input().split())

ans = 0
s = 0


def judge(x, y, z):
    width = y + 2 * z
    if width > x:
        return 0

    s = 1  # 上記条件を通過で1人は座れる
    rest = x - width

    width = y + z
    while width <= rest:
        s += 1
        width = y + z
        rest -= width
    return s


print(judge(X, Y, Z))
