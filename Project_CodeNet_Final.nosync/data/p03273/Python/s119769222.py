# 2019/03/28
# AtCoder Beginner Contest 107 - B

# Input
h, w = map(int, input().split())
al = list()
wcnt = [0 for i in range(w)]
wh = h

# Input Line and Count # in line
for i in range(h):
    a = input()
    lcnt = 0
    for j in range(w):
        if a[j] == "#":
            wcnt[j] += 1
            lcnt += 1

    if lcnt > 0:
        al.append(a)
    else:
        wh -= 1

# Output Line
for i in range(wh):
    wstr = ""
    for j in range(w):
        if wcnt[j] > 0:
            wstr += al[i][j]
    print(wstr)