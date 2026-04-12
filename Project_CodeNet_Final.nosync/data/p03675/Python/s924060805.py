n=int(input())
a=list(map(int,input().split()))
if n%2==0:
  print(*a[1::2][::-1]+a[0::2])
else:
  print(*a[0::2][::-1]+a[1::2])