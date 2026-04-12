N = int(input())
H = [int(_) for _ in input().split()]

ans = 0
k = 0
for h in H:
    if h >= k:
        ans += 1
    k = max(k, h)
print(ans)
