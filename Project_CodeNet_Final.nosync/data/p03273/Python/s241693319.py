def main():
    H, W = map(int, input().split())
    G = [input() for _ in range(H)]

    cond_r = [True] * H
    cond_c = [True] * W
    for r in range(H):
        if all(x == '.' for x in G[r]):
            cond_r[r] = False
    for c in range(W):
        if all(x == '.' for r in range(H) for x in G[r][c]):
            cond_c[c] = False
    for r, row in enumerate(G):
        if not cond_r[r]: continue
        for c, cell in enumerate(row):
            if not cond_c[c]: continue
            print(cell, end='')
        print()


if __name__ == '__main__':
    main()
