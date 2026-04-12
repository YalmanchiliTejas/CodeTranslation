n = int(input())
a_list = list(map(int,input().split()))
sum_a = sum(a_list)

sum = 0
for i in range(n):
  sum += a_list[i] * (sum_a-a_list[i])
  sum = sum%(10**9+7)
  sum_a -= a_list[i]
print(sum)