def main():
    h, w = map(int, input().split())
    a = [[j for j in input()] for i in range(h)]

    x, flg = (0, -1), False
    for i in range(h):
        for j in range(w):
            if a[i][j] == "#":
                if i == x[0] and j == x[1] + 1 or i == x[0] + 1 and j == x[1]:
                    x = i, j
                else:
                    break

        else:
            continue
        break

    else:
        flg = True

    if flg:
        print("Possible")
    else:
        print("Impossible")


if __name__ == '__main__':
    main()
