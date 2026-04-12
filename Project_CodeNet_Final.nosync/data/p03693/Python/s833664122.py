a = list(map(int,input().split()))
b = a[0]*100+a[1]*10+a[2]*1
if b%4==0:
  print("YES")
else:
  print("NO")