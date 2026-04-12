N = int(input())
max_num = 1
cnt = 0
list_num = [int(x) for x in input().split()]
for i in range(len(list_num)):
	if max_num <= list_num[i]:
		cnt += 1
		max_num = list_num[i]
print(cnt)