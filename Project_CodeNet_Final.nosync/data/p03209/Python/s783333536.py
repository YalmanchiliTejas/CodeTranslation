N, X = map(int, input().split())

nums = [1] * (N + 1)
for i in range(1, N + 1):
    nums[i] = nums[i - 1] * 2 + 3

memo = {}


def calc(N, X):
    if (N, X) in memo:
        return memo[N, X]

    if not 1 <= X <= nums[N]:
        return 0
    if N == 0:
        return 1
    if X == 1:
        return 0
    elif X <= nums[N - 1] + 1:
        memo[N, X] = calc(N - 1, X - 1)
    elif X <= nums[N - 1] + 2:
        memo[N, X] = calc(N - 1, nums[N - 1]) + 1
    elif X < 2 * nums[N - 1] + 2:
        memo[N, X] = calc(N - 1, nums[N - 1]) + 1 + calc(N - 1, X - nums[N - 1] - 2)
    else:
        memo[N, X] = 2 * calc(N - 1, nums[N - 1]) + 1
    return memo[N, X]


print(calc(N, X))