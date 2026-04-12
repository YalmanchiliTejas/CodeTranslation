h,w = list(map(int,input().split()))
grid = []
for i in range(h):
    a = input()
    if "#" in a:
        grid.append(a)

l = []
for i in range(w):
    s = ""
    for j in range(len(grid)):
        f = grid[j]
        s = s+f[i]
    if "#" in s:
        l.append(s)

ans = []
for i in range(len(l[0])):
    s = ""
    for j in range(len(l)):
        f = l[j]
        s = s+f[i]
    ans.append(s)
for i in ans:
    print(i)