n = int(input())
s = 0
a = list(map(int, input().split()))
sum_tmp = sum(a[1:len(a)])
for i in range(len(a)-1):
  s += a[i] * sum_tmp
  sum_tmp -= a[i + 1]
print(s % 1000000007)