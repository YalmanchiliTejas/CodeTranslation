n = int(input())
height = list(map(int,input().split()))

ans = 0

for i in range(n):
    h = height[i]
    if max(height[:i+1]) == h:
        ans += 1
print(ans)
        