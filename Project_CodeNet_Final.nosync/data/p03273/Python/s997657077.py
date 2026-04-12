def main():
    H, W = map(int, input().split(" "))
    grids = []
    for _ in range(H):
        line = input()
        if "#" in line:
            grids.append([l for l in line])
        else:
            continue
    for i in range(W):
        tmp = 0
        for grid in grids:
            if grid[i] == ".":
                tmp += 1
        if tmp == len(grids):
            for grid in grids:
                grid[i] = ""
    for grid in grids:
        print("".join(grid))


if __name__ == '__main__':
    main()