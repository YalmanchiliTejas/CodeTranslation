h,w = map(int,input().split())
a = []
list_w = []
list_h = []
for i in range(h):
    A = list(str(input()))
    a.append(A)
for i in range(h):
    cnt_w = 0
    cnt_h = 0
    for j in range(w):
        if a[i][j] == ".":
            cnt_w += 1
    if cnt_w == w:
        list_w.append(i)

for i in range(w):
    cnt_h = 0
    for j in range(h):
        if a[j][i] == ".":
            cnt_h += 1
    if cnt_h == h:
        list_h.append(i)

for i in list_w:
    for j in range(w):
        a[i][j] = "!"
for i in list_h:
    for j in range(h):
        a[j][i] = "!"


ans = []
for i in range(h):
    tmp = []
    for j in range(w):
        if a[i][j] == "#" or a[i][j] == ".":
            tmp.append(a[i][j])
    tmp = "".join(tmp)
    ans.append(tmp)
for i in ans:
    if i != '':
        print(i)