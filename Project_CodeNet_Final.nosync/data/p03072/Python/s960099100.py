N = int(input())
nums = list(map(int, input().split()))
ans=0
for i in range(len(nums)):
    if max(nums[0:i+1]) == nums[i]:
        ans = ans+1
print(ans)