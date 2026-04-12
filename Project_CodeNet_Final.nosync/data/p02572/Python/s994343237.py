n = int(input())
a = list(map(int,input().split()))
ans = 0
Sum = sum(a)
for i in range(n):
  Sum = Sum- a[i]
  ans = ans  + a[i] * Sum
if ans > 10 ** 9:
  ans = ans % (10 **9 + 7)
print(ans)