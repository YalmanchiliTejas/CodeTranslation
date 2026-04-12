h,w = [int(x) for x in input().split()]
a = [input() for _ in range(h)]

ans = "Possible"
for i in range(h-1):
    for j in range(w-1):
        if a[i][j+1] == a[i+1][j] == "#":
            ans = "Impossible"
            break
print(ans)