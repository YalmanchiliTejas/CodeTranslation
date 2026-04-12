h, w = map(int, input().split())
cnt = 0
for i in range(h):
    cnt += input().count("#")
print("Possible" if cnt == h + w - 1 else "Impossible")