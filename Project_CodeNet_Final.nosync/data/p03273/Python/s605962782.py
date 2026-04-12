hw = list(map(int, input().split()))
h = hw[0]
w = hw[1]
a = list()
for i in range(h):
    a.append(list(input()))
h_blank = list()
w_blank = list()
for i in range(h):
    flag = 0
    if not "#" in a[i]:
        h_blank.append(i)
for i in range(w):
    flag = 0
    for j in range(h):
        if a[j][i] == "#":
            break
        flag += 1
    if flag == h:
        w_blank.append(i)
x = 0
for i in h_blank:
    a.pop(i - x)
    x += 1
for i in range(h - x):
    y = 0
    for j in w_blank:
        a[i][j] = ""
        y += 1
for i in a:
    print("".join(i))
