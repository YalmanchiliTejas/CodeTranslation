N = int(input())
H = [int(x) for x in input().split()]
maxH = 0
ans = 0
for h in H:
    if maxH > h:
        continue
    ans += 1
    maxH = h
print(ans)
