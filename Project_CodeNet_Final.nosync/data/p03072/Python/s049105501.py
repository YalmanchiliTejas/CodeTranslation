n = int(input())
height_list = [int(i) for i in input().split()]

maxheight = 0
count = 0
for i in range(n):
    height = height_list[i]
    if height>=maxheight:
        count+=1
        maxheight=height
print(count)