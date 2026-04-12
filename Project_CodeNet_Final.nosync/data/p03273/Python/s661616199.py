def main():
    H, W = [int(i) for i in input().split()]
    grid = [list(input()) for _ in range(H)]
    grid = [l for l in grid if "#" in l]
    grid = list(zip(*grid))
    grid = [l for l in grid if "#" in l]
    grid = ["".join(l) for l in zip(*grid)]
    print(*grid, sep="\n")


if __name__ == "__main__":
    main()