################ C
n = int(input())
nums = list(map(int, input().split()))

total = 0
total_sum = sum(nums)
for num in nums:
    total_sum -= num 
    total += num * total_sum
    
print(total % 1000000007)   