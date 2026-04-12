def bin_search(temp, x, start, end):
	# print(temp)
	ind = -1
	while start <= end:
		middle = (start + end)//2
		# print(start, middle, end, x)
		if x > temp[middle]:
			ind = middle
			end = middle-1
		else:
			start = middle+1
	# print(ind)
	if ind == -1:
		temp += [x]
	else:
		temp[ind] = x




n = int(input())
arr = []
for i in range(n):
	arr += [int(input())]

temp = [arr[0]]
arr.pop(0)
for x in arr:
	bin_search(temp, x, 0, len(temp)-1)

print(len(temp))