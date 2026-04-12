n = int(input())
a = [int(i) for i in input().split()]

sum1 = 0
sum2 = 0

for _ in a:
  sum1 += _
  sum2 += (_*_)
sum1 = (sum1 * sum1)
print(((sum1 - sum2)//2)%1000000007)
