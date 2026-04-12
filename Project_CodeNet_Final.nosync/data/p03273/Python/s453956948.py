import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

h, w = na()
mas = []
li = []
for i in range(h):
    col = input()
    if "#" in col:
        mas.append(col)
for i in range(w):
    for j in range(len(mas)):
        if mas[j][i] == ".":
            if j == len(mas) - 1:
                li.append(i)
            continue
        else:
            break
for i in range(len(mas)):
    ans = ""
    for j in range(w):
        if j not in li:
            ans += mas[i][j]
    print(ans)

