N = int(input())
list_mountain_height = list(map(int, input().split()))

count_ocean_view = 0

for i in range(len(list_mountain_height)): 
	count = -1
	for k in list_mountain_height[:i+1]:
		if k > list_mountain_height[i]:
			break
		else:
			count += 1
	if count == i:
		count_ocean_view += 1
	else:
		continue

print(count_ocean_view)