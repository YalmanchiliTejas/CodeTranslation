h, w = map(int, input().split())
a = []
for _ in range(h):
    x = input()
    if "#" in x:
        a.append(x)
    else:
        h -= 1
for i in range(w - 1, -1, -1):
    for j in range(h):
        if a[j][i] == "#":
            break
    else:
        for k in range(h):
            a[k] = a[k][:i] + a[k][i + 1 :]
print(*a, sep="\n")