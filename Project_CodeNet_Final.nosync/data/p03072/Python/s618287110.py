n = int(input())
h = [int(x) for x in input().split()]

ans = 0
for i in range(n):
    if max(h[:i + 1]) == h[i]:
        ans += 1

print(ans)
