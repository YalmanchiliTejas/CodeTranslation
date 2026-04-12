N = int(input())
H = [int(i) for i in input().split()]
ans = 0
max_west = 0
for h in H:
    if h >= max_west:
        ans += 1
        max_west = h
print(ans)
