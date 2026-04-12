h,w = map(int,input().split())

grid = []
for i in range(h):
    row = str(input())

    for j in range(w):
        if row[j] == "#":
            grid.append(row)
            break

cls = []
for i in range(w):
    count = 0

    for j in range(len(grid)):    

        if grid[j][i] == "." :
            count += 1

    if count >= len(grid) :
        cls.append(i)

for i in range(len(grid)):
    for j in range(w) :
        if j not in cls:
            print(grid[i][j],end="")
    print()
        