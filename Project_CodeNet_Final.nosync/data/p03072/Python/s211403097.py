ryokan = int(input())
height = input().split()

counter = 1
tmp = int(height[0])

for i in range(1, ryokan):
    if int(height[i]) > tmp:
        tmp = int(height[i])
    if int(height[i]) >= tmp:
        counter += 1

print(counter)
