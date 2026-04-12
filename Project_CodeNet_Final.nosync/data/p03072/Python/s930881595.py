N = input()
mountain_heights = [int(i) for i in input().split()]
height_count = 0
result = 0

for height in mountain_heights:
    if height >= height_count:
        height_count = height
        result += 1

print(result)