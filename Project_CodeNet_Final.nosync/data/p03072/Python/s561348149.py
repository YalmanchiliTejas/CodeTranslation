a = int(input())
height_list = input().split()
int_height = []
for i in range(a):
    b = int(height_list[i])
    int_height.append(b)

count = 0 
for i in range(a):
    if max(int_height[:i+1]) == int_height[i]:
        count += 1
        


print(count)