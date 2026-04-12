N, X = list(map(int, input().split()))
mem = []
pt = []
mem.append(1)
pt.append(1)
for i in range(50):
    mem.append(mem[i] * 2 + 3)
    pt.append(pt[i] * 2 + 1)


def check_pt(n, layer, nowpt):
    if n == 0:
        return nowpt + 1
    elif layer == 1:
        return nowpt
    elif layer == mem[n]:
        return nowpt + pt[n]
    elif layer < mem[n - 1] + 2:
        return check_pt(n - 1, layer - 1, nowpt)
    elif layer == mem[n - 1] + 2:
        return check_pt(n - 1, layer - 2, nowpt + 1)
    else:
        return check_pt(n - 1, layer - (mem[n - 1] + 2), nowpt + pt[n - 1] + 1)


print(check_pt(N, X, 0))