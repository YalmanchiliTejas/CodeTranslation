h, w = map(int, input().split())
grid = []
ignore_i = []
ignore_j = []
for i in range(h):
    l = list(input())
    grid.append(l)
    
    if  not("#" in l):
        ignore_i.append(i)

for j in range(w):
    white = True
    for i in range(h): 
        if grid[i][j] == "#":
            white = False
            break
    if white:
        ignore_j.append(j)

# print(ignore_i)
# print(ignore_j)

for i in range(h):
    if i in ignore_i:
        continue

    for j in range(w):
        if j in ignore_j:
            continue
        print(grid[i][j], end="")
    print("\n")