n = int(input())
list1 = list(map(int, input().split()))
s = 0
ss = sum(list1)
for i in range(n):
  a = list1[i]
  ss = ss - a
  p = a * ss
  s += p
print(s % (10**9 + 7))