#ABC-107-B
def main():
    H, W = map(int, input().split())
    grid = []
    for _ in range(H):
        row = list(input())
        grid.append(row)

    for i in reversed(range(H)):
        if not "#" in grid[i]:
            del grid[i]
            H -= 1

    for j in reversed(range(W)):
        flag = True
        for i in reversed(range(H)):
            if grid[i][j] == "#":
                flag = False
                break
        if flag == True:
            for i in range(H):
                del grid[i][j]
    for row in grid:
        print("".join(row))

if __name__ == "__main__":
    main()
