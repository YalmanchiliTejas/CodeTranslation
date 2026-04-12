def solve():
    h, w = map(int, input().split())
    grid = list(input() for _ in range(h))
    new_grid = []
    white_columns = set([i for i in range(w)])
    for line in grid:
        if line != "." * w:
            new_grid.append(line)
            white_columns &= set([i for i, c in enumerate(line) if c == "."])
    if white_columns:
        for line in new_grid:
            new_line = "".join([c for i, c in enumerate(line) if i not in white_columns])
            print(new_line)
    else:
        print("\n".join(new_grid))


if __name__ == "__main__":
    solve()
