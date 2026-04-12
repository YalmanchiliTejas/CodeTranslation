_ = input() 
lst = [int(i) for i in  input().split()]
height = 0
cnt = 0
for i in lst:
	if height <= i:
		height = i
		cnt += 1
print(cnt)