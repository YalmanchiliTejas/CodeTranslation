def main():
    H, W = map(int, input().split())
    A = [input() for _ in range(H)]

    tmp = 0
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                tmp += 1

    if tmp == H + W - 1:
        print('Possible')
    else:
        print('Impossible')


if __name__ == "__main__":
    main()
