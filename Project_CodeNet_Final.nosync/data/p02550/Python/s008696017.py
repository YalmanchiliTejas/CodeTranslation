import sys
input = sys.stdin.readline
INF = 10**18
sys.setrecursionlimit(10**6)


def li():
    return [int(x) for x in input().split()]


N, X, MOD = li()


n = X
nums = [X]
loop_start_i = -INF
for i in range(1, N):
    n = pow(n, 2, MOD)
    if n in nums:
        loop_start_i = nums.index(n)
        break
    nums.append(n)
# total %= MOD
loop_length = len(nums) - loop_start_i
loop_cnt = (N - loop_start_i) // loop_length
r = (N - loop_start_i) % loop_length
sum_per_loop = sum(nums[loop_start_i:])
ans = sum(nums[:loop_start_i]) + sum_per_loop * loop_cnt + sum(nums[loop_start_i:loop_start_i+r])
print(ans)