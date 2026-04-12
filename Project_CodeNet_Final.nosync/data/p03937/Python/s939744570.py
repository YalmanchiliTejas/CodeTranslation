h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
cnt = 0
for i in range(h):
    cnt += a[i].count("#")
print("Possible" if cnt == h + w - 1 else "Impossible")