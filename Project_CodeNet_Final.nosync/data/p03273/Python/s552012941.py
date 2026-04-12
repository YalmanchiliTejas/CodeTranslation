# ABC107B - Grid Compression
def main():
    H, W, *A = open(0).read().split()
    H, W = int(H), int(W)
    X, Y = [0] * H, [0] * W
    for i, a in enumerate(A):
        for j, x in enumerate(a):
            if x == "#":
                X[i], Y[j] = 1, 1
    ans = []
    for i, x in enumerate(X):
        cur = ""
        for j, y in enumerate(Y):
            if x and y:
                cur += A[i][j]
        if cur:
            ans.append(cur)
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()