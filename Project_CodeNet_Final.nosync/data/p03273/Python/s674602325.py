#ABC107-B
h,w = map(int,input().split())
grid = [input() for _ in range(h)]

row = [False for _ in range(h)]
col = [False for _ in range(w)]

for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            row[i] = True
            col[j] = True
            
            
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(grid[i][j],end='')
                
        print()
                