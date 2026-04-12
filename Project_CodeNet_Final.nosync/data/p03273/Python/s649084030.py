import sys

readline = sys.stdin.readline

def main():
    H, W = map(int, readline().split())
    grid = []
    for _ in range(H):
        A = list(readline()[:-1])
        if '#' in A:
            grid.append(A)

    for i in range(W-1, -1, -1):
        flag = True
        for j in range(len(grid)):
            if grid[j][i] == '#':
                flag = False
                break
        if flag:
            for k in range(len(grid)):
                del grid[k][i]
    
    for k in range(len(grid)):
        print(''.join(grid[k]))


if __name__ == "__main__":
    main()
