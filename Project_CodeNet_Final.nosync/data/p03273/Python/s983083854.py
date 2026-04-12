def main():
    h, w = map(int, input().split())
    a = [list(input()) for _ in range(h)]
    pass_row = []
    pass_col = []
    for i in range(h):
        if "#" not in a[i]:
            pass_row.append(i)
    left_row = h - len(pass_row)
    for j in range(w):
        tmp = 0
        for i in range(h):
            if i not in pass_row and a[i][j] == ".":
                tmp += 1
        if tmp == left_row:
            pass_col.append(j)
    for i in range(h):
        if i not in pass_row:
            for j in range(w):
                if j not in pass_col:
                    print(a[i][j], end="")
            print()


if __name__ == '__main__':
    main()

