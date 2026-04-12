Nums = raw_input().split()
prod = int(Nums[0]) * 100
prod += int(Nums[1]) * 10
prod += int(Nums[2])
# print prod
if(prod % 4 == 0):
	print "YES"
else:
	print "NO"
