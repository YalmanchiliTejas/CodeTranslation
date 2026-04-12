n = int(input())
height = list(map(int, input().split()))
num = 1
for i in range(1, n):
    if max(height[:i+1]) == height[i]:
        num += 1
print(num)