N = input()
nums = list(map(int, input().split()))
rests = []
rest_sum = 0
for i in reversed(nums):
    rest_sum += i
    rests.append(rest_sum)

sum_num = 0
for i in range(len(nums)-1):
    sum_num += nums[i]*rests[-(i+2)]
    if sum_num > 10**9 + 7:
        sum_num = sum_num % (10**9 + 7)
    

print(sum_num)