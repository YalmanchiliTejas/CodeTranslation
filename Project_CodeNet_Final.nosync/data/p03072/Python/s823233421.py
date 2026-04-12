n = int(input())
height = tuple(map(int, input().split()))
ans = 1
mt_max = height[0]
for i in range(1, n):
    if mt_max <= height[i]:
        ans += 1
        mt_max = height[i]
print(ans)