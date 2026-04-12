
n = int(input())
heights = [int(h) for h in input().split()]

max_height = 0
result = 0
for height in heights:
    if max_height <= height:
        result += 1
        max_height = height
print(result)
