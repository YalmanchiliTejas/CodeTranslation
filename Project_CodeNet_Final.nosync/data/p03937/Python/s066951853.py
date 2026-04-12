def main():
    H, W = (int(i) for i in input().split())
    c = [input() for i in range(H)]
    cnt = 0
    for h in range(H):
        for w in range(W):
            if c[h][w] == "#":
                cnt += 1
    if H+W-1 == cnt:
        print("Possible")
    else:
        print("Impossible")


if __name__ == '__main__':
    main()
