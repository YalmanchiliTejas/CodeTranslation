from collections import deque
n = int(input())
nums = []
ans = deque()
for i in range(n):
    nums.append(int(input()))
if n == 2:
    print(abs(nums[0]-nums[1]))
elif n == 3:
    nums.sort
    print(max(abs(nums[0]-nums[1])+abs(nums[1]-nums[2]),abs(nums[0]-nums[2])+abs(nums[0]-nums[1]),abs(nums[2]-nums[1])+abs(nums[2]-nums[0])))
else:
    nums.sort()
    nums = deque(nums)
    a = nums.popleft()
    ans.append(a)
    b = nums.pop()
    ans.append(b)
    c = nums.popleft()
    ans.append(c)
    anser = abs(a-b) + abs(b-c)
    while len(nums) != 0:
        imin = nums[0]
        imax = nums[-1]
        amin = ans[0]
        amax = ans[-1]
        do = (abs(imin-amin),abs(imin-amax),abs(imax-amin),abs(imax-amax))
        domax = max(do)
        doindex = do.index(domax)
        if doindex == 0:
            nums.popleft()
            ans.appendleft(imin)
        elif doindex == 1:
            nums.popleft()
            ans.append(imin)
        elif doindex == 2:
            nums.pop()
            ans.appendleft(imax)
        else:
            nums.pop()
            ans.append(imax) 
        anser += domax
    print(anser)
