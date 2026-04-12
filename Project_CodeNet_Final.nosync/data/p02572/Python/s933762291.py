n = int(input())
a = [int(s) for s in input().split()]
s=sum(a)

total=0

for i in range(n-1):
  s=s-a[i]
  total=total+a[i]*s%1000000007
  
print(total%1000000007)
