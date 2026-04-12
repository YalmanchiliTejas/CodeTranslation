def main():
    h, w = map(int, input().split())
    a = [["." for j in range(w+2)] for i in range(h+2)]
    for i in range(h):
        s = list(input().rstrip())
        for j in range(w):
            a[i+1][j+1] = s[j]
    y, x = 1, 1
    f = True
    while y != h or x != w:
        a[y][x] = "."
        if a[y-1][x] == "#" or a[y][x-1] == "#" or (a[y+1][x] == "#" and a[y][x+1] == "#"):
            f = False
            break
        else:
            if a[y+1][x] == "#":
                y += 1
            else:
                x += 1
    if a[y-1][x] == "#" or a[y][x-1] == "#":
        f = False
    if f:
        print("Possible")
    else:
        print("Impossible")

if __name__ == "__main__":
    main()