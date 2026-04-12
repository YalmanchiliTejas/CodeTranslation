n = int(input())
nums = []
for _ in range(n):
    nums.append(int(input()))

nums.sort()
# 奇数は2通り
# w型とm型
if n % 2 == 1:
    w = -2*sum(nums[:n//2])+nums[n//2]+nums[n//2+1]+2*sum(nums[n//2+2:])
    m = -2*sum(nums[:n//2-1])-nums[n//2-1]-nums[n//2]+2*sum(nums[n//2+1:])
    print(max(w,m))
# 偶数は1通り
else:
    print(-2*sum(nums[:n//2-1])-nums[n//2-1]+nums[n//2]+2*sum(nums[n//2+1:]))