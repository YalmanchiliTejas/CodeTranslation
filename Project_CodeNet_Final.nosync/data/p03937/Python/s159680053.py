def main():
    from collections import deque
    H, W = (int(i) for i in input().split())
    c = [input() for i in range(H)]
    seen = [[0]*W for i in range(H)]

    def bfs(sy, sx):
        que = deque()

        seen[sy][sx] = 1
        que.append((sy, sx))
        d = ((1, 0), (0, 1))
        while que:
            uy, ux = que.popleft()
            for dy, dx in d:
                next_y = uy + dy
                next_x = ux + dx
                if not(0 <= next_y < H and 0 <= next_x < W):
                    continue
                if seen[next_y][next_x] != 0:
                    continue
                if c[next_y][next_x] == '.':
                    continue
                seen[next_y][next_x] = 1
                que.append((next_y, next_x))
                break
    bfs(0, 0)
    num = 0
    cnt = 0
    for h in range(H):
        for w in range(W):
            if c[h][w] == "#":
                num += 1
            if seen[h][w] == 1:
                cnt += 1
    # print(*seen, sep="\n")
    if seen[-1][-1] == 1 and num == cnt:
        print("Possible")
    else:
        print("Impossible")


if __name__ == '__main__':
    main()
