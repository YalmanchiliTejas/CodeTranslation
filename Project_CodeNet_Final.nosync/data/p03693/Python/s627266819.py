nums = [int(x) for x in input().split()]
ans = nums[0]*100 + nums[1] * 10 + nums[2]

if ans % 4 == 0:
	print("YES")
else:
	print("NO")