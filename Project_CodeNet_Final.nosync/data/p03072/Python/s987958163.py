N = int(input())
H = tuple(map(int, input().split(' ')))

max_h = 0
ans = 0
for h in H:
    if h >= max_h:
        max_h = h
        ans += 1

print(ans)
