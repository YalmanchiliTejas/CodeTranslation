N = int(input())
mountain_height = list(map(int, input().split(" ")))

max_height = 0
ans = 0
for i in range(N):
    if mountain_height[i] >= max_height:
        ans += 1
        max_height = mountain_height[i]
print(ans)