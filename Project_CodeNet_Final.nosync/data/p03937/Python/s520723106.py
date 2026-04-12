h,w = [int(x) for x in input().split()]
a = []
for _ in range(h):
    tmp = list(input())
    a.append(tmp)

ans = "Possible"
for i in range(h-1):
    for y in range(w-1):
        if a[i][y+1] == a[i+1][y] == "#":
            ans = "Impossible"
            break
print(ans)