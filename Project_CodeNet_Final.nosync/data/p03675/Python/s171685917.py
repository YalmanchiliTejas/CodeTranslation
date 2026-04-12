n=int(input())
a=list(map(int,input().split()))
if n==1:
  print(a[0])
else:
  print(*(a[n-1::-2]+(a[n-2::-2])[::-1]))