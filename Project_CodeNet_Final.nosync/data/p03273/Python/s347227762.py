# coding: utf-8

h, w = [int(i) for i in input().split()]

a = [list(input()) for _ in range(h)]

for i in range(h - 1, -1, -1):
    if all([x == "." for x in a[i]]):
        del(a[i])

for j in range(w - 1, -1, -1):
    flg = True
    for i in range(len(a)):
        if a[i][j] == "#":
            flg = False
            break

    if flg:
        for i in range(len(a)):
            del(a[i][j])

for i in a:
    print(''.join(i))