import numpy as np
def main():
    H,W = map(int,input().split())
    grid = np.array([list(input()) for _ in range(H)],str)
    grid = grid[:,np.any(grid == '#',axis = 0)]
    grid = grid[np.any(grid == '#',axis = 1),:]
    print('\n'.join(''.join(row) for row in grid))
if __name__ == '__main__':
    main()