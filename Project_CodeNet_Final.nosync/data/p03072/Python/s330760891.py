N = int(input())
heights = list(map(int,input().split()))
ans = 1
for i in range(N):
    if i == 0:
        continue
    if max(heights[:i]) <= heights[i]:
        ans += 1
print(ans)