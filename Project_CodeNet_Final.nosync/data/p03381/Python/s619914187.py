def solve(n, nums):
    sorted_nums = sorted(nums)
    low = sorted_nums[n/2 - 1]
    high = sorted_nums[n/2]

    for i in xrange(n):
        if nums[i] <= low:
            print high
        else:
            print low
    return


n = int(raw_input())
nums = map(int, raw_input().split())
solve(n, nums)
