n=int(input())

l = 1000000007
a=list(map(int,input().split()))
s = sum(a)
num = 0
for i in range(n):
  s = s- a[i]
  num =num+a[i]*s
else:
  print(num%l)

