n = int(input())
height_list = list(map(int,input().split()))

max_list = []
for i in range(n):
    if i == 0:
        max_list.append(height_list[i])
    else:
        if height_list[i] >= max_list[-1]:
            max_list.append(height_list[i])

print(len(max_list))