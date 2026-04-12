x = input()
x = x.split(" ")

nums = []

for i in range(0,len(x)):
	nums.append(int(x[i]))

total = nums[0]*100+nums[1]*10+nums[2]

if total % 4 == 0:
	print("YES")
else:
	print("NO")