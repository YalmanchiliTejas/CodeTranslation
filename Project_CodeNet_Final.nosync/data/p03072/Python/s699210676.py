n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(1, len(h)):
    if max(h[:i]) <= h[i]:
        ans += 1
print(ans)