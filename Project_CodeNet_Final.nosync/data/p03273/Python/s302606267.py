def main():
    H, W = map(int, input().split())
    A = [[c for c in input()] for _ in range(H)]
    sniprows = set()
    for i in range(H):
        snip = True
        for j in range(W):
            if A[i][j] == "#":
                snip = False
        if snip:
            sniprows.add(i)
    snipcols = set()
    for j in range(W):
        snip = True
        for i in range(H):
            if A[i][j] == "#":
                snip = False
        if snip:
            snipcols.add(j)
    for i in range(H):
        if i in sniprows:
            continue
        ans = ""
        for j in range(W):
            if j in snipcols:
                continue
            ans += A[i][j]
        print(ans)


if __name__ == "__main__":
    main()
