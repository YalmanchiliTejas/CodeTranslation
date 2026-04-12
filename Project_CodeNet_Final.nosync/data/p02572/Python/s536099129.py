N = int(input())
nums = list(map(int, input().split()))
n_sums = [0 for _ in range(N)]
n_sums[0] = nums[N-1]
MOD = 10**9 + 7
for i in range(N-1):
  n_sums[i+1] = n_sums[i] + nums[N-i-2]
  answer = 0
for i in range(N-1):
  answer += n_sums[N-i-2] * nums[i]
  answer = answer%MOD
print(answer)