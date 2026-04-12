n = int(input())
height = list(map(int, input().split()))

cnt = 1
for i in range(1, n):
    if height[i] == max(height[:i+1]):
        cnt += 1

print(cnt)