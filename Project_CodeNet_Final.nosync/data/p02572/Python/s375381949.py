MOD = 1000000007

n = int(input())
str_ary = input().split()
ary = [int(c) for c in str_ary]
# ary = []
# queue = [0 for i in range(n)]
# for i int range(n):
#   num = int(str_ary[i])
#   ary.append(num)
#   for j int range(i):
#     pre_queue = []
#     queue.append(pre_queue)

result = 0
sum = sum(ary[i] for i in range(n))
# for diff in range(1, n):
#   for i in range(n - diff):
#     # print(diff, i, i + diff)
#     sum += ary[i] * ary[i + diff] % MOD
for i in range(n):
  sum -= ary[i]
  result += ary[i] * sum

print(result % MOD)