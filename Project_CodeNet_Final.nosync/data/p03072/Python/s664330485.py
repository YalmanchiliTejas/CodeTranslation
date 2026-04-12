N = int(input())
H = map(int, input().split())
ans = 0
max_height = 0

for h in H:
    if h >= max_height:
        max_height = h
        ans += 1

print(ans)