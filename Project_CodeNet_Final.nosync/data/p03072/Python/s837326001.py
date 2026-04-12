N = int(input())
height = list(map(int, input().split()))
count = 1
temp = [height[0]]
for i in range(1, N):
  temp.append(height[i])
  if max(temp) <= height[i]:
    count += 1
print(count)