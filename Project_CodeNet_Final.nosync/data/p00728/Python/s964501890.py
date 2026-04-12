while True:
    n = int(input())
    if n == 0:
        break

    nums = [int(input()) for _ in range(n)]
    max_num = max(nums)
    min_num = min(nums)
    nums.remove(max_num)
    nums.remove(min_num)
    print(sum(nums) // len(nums))

