H,W = map(int,input().split())
grid = []
for i in range(H):
    a = input()
    l = []
    for i in a:
        l.append(i)
    grid.append(l)
grid_1 = []
delete = []
for i,job in enumerate(grid):
    count = 0
    for j in job:
        if(j == "."):
            count += 1
    if(count != W):
        grid_1.append(job)
count = 0
for i in delete:
    grid.pop(i-count)
    count += 1
grid_3 = []
for Row in zip(*grid_1):
    w = len(Row)
    count = 0
    for j in Row:
        if(j == "."):
            count += 1
    if(count != w):
        grid_3.append(Row)
for Row in zip(*grid_3):
    ans = ""
    for j in Row:
        ans += j
    print(ans)