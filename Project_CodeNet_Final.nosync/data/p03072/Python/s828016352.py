number = int(input())
height = list(map(int,input().split()))
count = 1
height_max = height[0]

for i in range(1,number):
    if height[i] >= height_max:
        count += 1
        height_max = height[i]
print(count)
