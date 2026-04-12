def main():
    height, width = map(int, input().split())
    grid = [list(input()) for _ in range(height)]
    count = 0
    for g in grid:
        count += g.count("#")
    print("Possible" if count == height + width - 1 else "Impossible")


if __name__ == '__main__':
    main()

