def solve(h, w, a):
    a = list(map(list, a))
    total = 0
    for r in range(h):
        for c in range(w):
            if a[r][c] == "#":
                total += 1
    que = [(0,0)]
    a[0][0] = "."
    while que:
        cr, cc = que.pop(0)
        for dr, dc in [(1,0),(0,1)]:
            nr, nc = cr+dr, cc+dc
            if (0 <= nc < w) and (0 <= nr < h) and a[nr][nc] == "#":
                a[nr][nc] = "."
                que.append((nr, nc))
    return "Possible" if (a[h-1][w-1] == ".") and (total == h+w-1) else "Impossible"

h, w = map(int, input().split())
a = [input() for r in range(h)]
print(solve(h, w, a))