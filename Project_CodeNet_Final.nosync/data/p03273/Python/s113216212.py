h,w=map(int,input().split())
grid=[list(input())  for i in range(h)]
for i in range(w)[::-1]:
    a=[grid[j][i] for j in range(h)]
    if not "#" in a:
        for j in range(h):
            del grid[j][i]
for i in grid:
    if "#" in i:print(*i,sep="")
    