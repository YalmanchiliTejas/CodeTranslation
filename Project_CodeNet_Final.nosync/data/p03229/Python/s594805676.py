all_num = int(input())
nums = []
for i in range(all_num):
    nums.append( int(input()) )
	
nums = sorted(nums)

sort_nums = []
loop_num = int(all_num/2)
for i in range( loop_num ):
    if i % 2 == 0:
        sort_nums.append(nums[i])
        sort_nums.insert(0,nums[-(i+1)])
    else:
        sort_nums.insert(0,nums[i])
        sort_nums.append(nums[-(i+1)])
    
if len( nums ) % 2 == 1:
    center_index = int(len(nums)/2)
    center_num = nums[center_index]
    if abs(center_num - sort_nums[0]) > abs(center_num - sort_nums[-1]):
        sort_nums.insert(0,center_num)
    else :
        sort_nums.append(center_num)


total = 0
for i in range( len(sort_nums)-1 ):
    total = total + abs(sort_nums[i] - sort_nums[i+1])

print(total)