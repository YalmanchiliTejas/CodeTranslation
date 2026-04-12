h,w = map(int,input().split())
li = []
for i in range(h):
    a = list(input())
    li.append(a)
li2 = li.copy()
c = 0
for i in range(h):
    for j in range(w):
        c = 0
        if li[i][j] == ".":
            continue
        elif li[i][j] == "#":
            c = 1
            break
    if c == 0:
        li[i] = ["a"] * w
d = 0
n = []
for i in range(w):
    for j in range(h):
        d = 0
        if li[j][i] == "." or li[j][i] == "a":
            continue
        else:
            d = 1
            break
    if d == 0:
        n.append(i)
for i in n:
    for j in range(h):
        li[j][i] = "a"

for i in range(h):
    grid = ""
    for x in li[i]:
        if x != "a":
            grid += x
    if grid != "":
        print(grid)