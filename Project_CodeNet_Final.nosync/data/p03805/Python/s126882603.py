import itertools
nums = [int(e) for e in input().split()]
pairs = []
count = 0
for i in range(nums[1]):
    s = [int(t) for t in input().split()]
    pairs.append(s)
lis = [i for i in range(1,nums[0]+1)]
permutatin_lis = itertools.permutations(lis)
for one in permutatin_lis:
    if(one[0] != 1):
        continue
    else:
        for i in range(nums[0]-1):
            checker = [one[i],one[i+1]]
            checker.sort()
            if checker in pairs:
                pass
            else:
                break
        else:
            count += 1
print(count)