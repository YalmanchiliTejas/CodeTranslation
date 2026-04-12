import sys


def main():
    H, W = map(int, input().split())
    A = [list(input()) for _ in range(H)]

    hash = []
    for h in range(H):
        for w in range(W):
            if A[h][w] == "#":
                hash.append((h, w))

    if hash == []:
        print('Impossible')
        sys.exit()

    s = hash[0]

    nd = ((1, 0), (0, 1))

    q = [s]
    cnt = 1
    while q:
        x0, y0 = q[0]
        del q[0]
        for dx, dy in nd:
            x = x0 + dx
            y = y0 + dy
            if x < H and y < W:
                if A[x][y] == "#":
                    cnt += 1
                    q.append((x, y))
                    break

    if cnt == len(hash):
        print('Possible')
    else:
        print('Impossible')

main()
