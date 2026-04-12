n = int(input())
heights = [int(x) for x in input().split()]

max_height = 0
counter = 0

for i in range(n):
    max_height = max(heights[:i+1])
    if max_height <= heights[i]:
        counter += 1

print(counter)