def resolve():
    '''
    code here
    '''
    import numpy as np
    H, W = [int(item) for item in input().split()]
    grid = [[item for item in input()] for _ in range(H)]

    temp_grid = []
    for line in grid:
        temp = [item == '#' for item in line]
        if any(temp):
            temp_grid.append(line)
            
    temp_grid = np.array(temp_grid)
    temp_grid2 = []
    for j in range(W):
        line = temp_grid[:,j]
        temp = [item == '#' for item in line]
        if any(temp):
            temp_grid2.append(line)

    
    temp_grid2 = np.array(temp_grid2)
    res = np.rot90(temp_grid2, 3)
    
    for line in res:
        print(''.join(line[::-1]))




if __name__ == "__main__":
    resolve()
