N, X, M = map(int, input().split())
x = X
nums = []
isSearched = [False] * (M+1)
isSearchedNums = [-1] * (M+1)
n = 0
looped = 0
while True:
    x = (x*x) % M
    if isSearched[x]:
        looped = isSearchedNums[x]
        break
    isSearched[x] = True
    isSearchedNums[x] = n
    nums.append(x)
    n+=1
if (isSearched[0]):
    ans = X
    for i in range(min((N-1), len(nums))):
        ans += nums[i]

    print(ans)
else:
    ans = X
    al = 0
    d = len(nums) - looped
    for i in range(looped, len(nums)):
        al += nums[i]
    if N - 1 > len(nums):
        N -= len(nums)
        ans += sum(nums)
        ans += al * ((N-1) // d)
        for i in range(looped, ((N-1) % d) + looped):
            ans += nums[i]
    else:
        for i in range(N - 1):
            ans += nums[i]

    print(ans)

