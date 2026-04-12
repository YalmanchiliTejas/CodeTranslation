h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

cnt = sum([row.count("#") for row in a])
print("Possible" if cnt == h + w - 1 else "Impossible")