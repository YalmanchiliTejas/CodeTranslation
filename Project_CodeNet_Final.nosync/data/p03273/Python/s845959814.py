def main():
    h, w = map(int, input().split())
    board = []

    cddt = []
    omission_line = 0
    for i in range(h):
        line = input()
        if line == "." * w:
            omission_line += 1
        else:
            cells = list(line)
            for n, c in enumerate(cells):
                if c == ".":
                    cddt.append(n)
            board.append(cells)

    for line in board:
        for i, c in enumerate(line):
            if (cddt.count(i) + omission_line) != h:
                print(c, end="")
        print("")


if __name__ == '__main__':
    main()
