

N = int(input())
H = list(map(int, input().split()))
ans = 0
max_height = -1
for h in H:
    if h >= max_height:
        ans += 1
        max_height = h
print(ans)
