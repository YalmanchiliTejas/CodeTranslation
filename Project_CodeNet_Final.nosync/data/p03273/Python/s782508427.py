h,w = map(int,input().split())
a = []
yoko = [False]*h
tate = [False]*w
for i in range(h):
    s = input()
    a.append(s)
cnt = 0
for i in range(h):
    state = False
    cnt = 0
    for j in range(w):
        if a[i][j] == ".":
            cnt += 1
    if cnt == w:
        yoko[i] = True
cnt = 0
for i in range(w):
    state = False
    cnt = 0
    for j in range(h):
        if a[j][i] == ".":
            cnt += 1
    if cnt == h:
        tate[i] = True

for i in range(h):
    if yoko[i] == True:
        continue
    else:
        ans = ""
        for j in range(w):
            if tate[j] == True:
                continue
            else:
                ans += a[i][j]
        print(ans) 
