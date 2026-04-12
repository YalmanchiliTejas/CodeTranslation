N = int(input())
heights = list(map(int, input().split()))
ans = 1
for i in range(1, N):
    if heights[i] >= max(heights[:i]):
        ans += 1
print(ans)
