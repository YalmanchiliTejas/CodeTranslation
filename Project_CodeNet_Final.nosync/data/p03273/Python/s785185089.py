H, W = map(int,input().split())
a = [list(input()) for i in range(H)]
ans1 = []

for i in range(H):
    sharp_cnt = a[i].count("#")
    if sharp_cnt != 0:
        ans1.append(a[i])

slicer = []
for j in range(W):
    sharp_cnt = 0
    for i in range(len(ans1)):
        if ans1[i][j] == "#":
            sharp_cnt +=1
    if sharp_cnt == 0:
        slicer.append(j)

del_cnt = 0
for i in slicer:
    i = i - del_cnt
    for j in ans1:
        del j[i]
    del_cnt += 1

for i in ans1:
    print(*i, sep = "")