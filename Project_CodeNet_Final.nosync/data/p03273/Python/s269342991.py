#!python3

# input
H, W = list(map(int, input().split()))
a = [input() for _ in range(H)]


def main():
    r, c = [], []
    # check rows
    for i in range(H):
        if a[i] != "." * W:
            r.append(i)

    # check columns
    for j in range(W):
        for i in range(H):
            if a[i][j] == "#":
                c.append(j)
                break

    for i in r:
        for j in c:
            print(a[i][j], end="")
        print("")


if __name__ == "__main__":
    main()
