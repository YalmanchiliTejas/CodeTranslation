import  math
def getN():
    return int(input())


def getNM():
    return map(int, input().split())


def getList():
    return list(map(int, input().split()))

n = getN()
nums = []


for i in range(n):
  nums.append(getN())

if n == 2:
    print(abs(nums[0]-nums[1]))

if n > 2:
    half = int(math.floor(n/2))
    nums.sort()
    nums1 = nums[:half]
    nums2 = nums[half:]
    nums2[1], nums2[-1] = nums2[-1], nums2[1]

    tmp = nums2[0]
    diff = 0
    diff2 = 0
    for i in range(half):
        num = nums2[i]
        diff += abs(tmp-num)
        tmp = num

        num = nums1[i]
        diff += abs(tmp - num)
        tmp = num

    if n%2 == 1:
        diff += abs(tmp-nums2[-1])

    if n%2 == 1:
        nums1 = nums[:half+1]
        nums2 = nums[half+1:]
        nums1[0], nums1[-2] = nums1[-2], nums1[0]

        tmp = nums1[0]
        for i in range(half):
            num = nums1[i]
            diff2 += abs(tmp - num)
            tmp = num

            num = nums2[i]
            diff2 += abs(tmp - num)
            tmp = num

        diff2 += abs(tmp-nums1[-1])

    #print(nums1)
    #print(nums2)
    print(max(diff, diff2))
"""
3 4 5 9
1 1 3
"""
