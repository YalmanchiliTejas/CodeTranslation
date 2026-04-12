N = int(input())
heights = list(map(int, input().split()))
result = []
max_height = 0
for height in heights:
  if max_height <= height:
    result.append(1)
    max_height = height
print(sum(result))
