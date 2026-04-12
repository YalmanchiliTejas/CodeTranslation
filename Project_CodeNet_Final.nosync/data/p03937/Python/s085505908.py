def main():
    H, W = map(int, input().split())
    A = [input() for _ in range(H)]
    cnt = 0
    for i in range(H):
        for j in range(W):
            if A[i][j] == "#":
                cnt += 1
    if cnt == H+W-1:
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()
