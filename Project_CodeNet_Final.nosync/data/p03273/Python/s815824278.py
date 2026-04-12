# coding: utf-8

# https://atcoder.jp/contests/abc107


def main():
    H, W = map(int, input().split())
    a = [None] * H
    for i in range(H):
        a[i] = input()

    b = []
    for i in range(H):
        if any([x == "#" for x in a[i]]):
            b.append(a[i])
    
    idx = []
    for j in range(W):
        if any([b[i][j] == "#" for i in range(len(b))]):
            idx.append(j)

    for i in range(len(b)):
        for j in range(W):
            if j in idx:
                print(b[i][j], end="")
        print()


main()
# print(main())
