_ = input()
nums = [int(x) for x in input().split(" ")]
res = 0
sums = []
for n in nums[1:][::-1]:
    if sums:
        sums.append(sums[-1]+n)
    else:
        sums.append(n)
sums.reverse()
#print(sums)
for i, ni in enumerate(nums[:-1]):
    res += ni*sums[i]
    res %= 10**9 + 7
print(res)