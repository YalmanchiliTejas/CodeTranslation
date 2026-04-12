import numpy as np
H,W = map(int,input().split())
grid = []
for i in range(H):
    mojiretsu = input()
    moji = []
    for k in range(len(mojiretsu)):
        moji.append(mojiretsu[k])
    grid.append(moji)
grid = np.array(grid)
flug1 = True
flug2 = True
flug3 = False
flug4 = False
while flug1:
    for i in range(grid.shape[0]):
        if np.all(grid[i,:] == "."):
            grid = np.delete(grid, i, 0)
            flug3 = False
            break
        else:
            flug3 = True
    if flug3 == True:
        flug1 = False
while flug2:
    for j in range(grid.shape[1]):
        if np.all(grid[:,j] == "."):
            grid = np.delete(grid, j, 1)
            flug4 = False
            break
        else:
            flug4 = True
    if flug4 == True:
        flug2 = False
for height in range(grid.shape[0]):
    print("".join(list(grid[height,:]))) 