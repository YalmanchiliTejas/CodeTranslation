h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

# 行を削除
for i in range(h-1, -1, -1):
    if '#' not in a[i]:
        del a[i]

# 列を削除
h = len(a)
for i in range(w-1, -1, -1):
    res = True
    for j in range(h):
        if a[j][i] == '#':
            res = False
    if res:
        for j in range(h):
            del a[j][i]
for i in range(len(a)):
    print("".join(a[i]))