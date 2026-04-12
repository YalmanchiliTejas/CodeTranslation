h,w = map(int, input().split())
grid = [list(input()) for i in range(h)]
for i in reversed(range(h)):
    if all(j=="." for j in grid[i]):
        grid.pop(i)
for i in reversed(range(w)):
    if all(j[i]=="." for j in grid):
        for j in grid:
            j.pop(i)
for i in grid:
    print("".join(i))