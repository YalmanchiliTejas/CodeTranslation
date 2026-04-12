def solve():
    H, W = map(int, input().split())
    row = [False for _ in range(H)]
    column = [False for _ in range(W)]
    a = [['' for _ in range(W)] for _ in range(H)]
    for i in range(H):
        a[i] = input()
        for j in range(W):
            if a[i][j] == '#':
                row[i] = True
                column[j] = True

    for i in range(H):
        if row[i]:
            for j in range(W):
                if column[j]:
                    print(a[i][j], end='')
            print()


if __name__ == "__main__":
    solve()
