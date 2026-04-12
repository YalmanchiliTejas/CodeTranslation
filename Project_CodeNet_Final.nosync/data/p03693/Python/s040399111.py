num = input().split()
out = int(num[0] + num[1] + num[2])
if out%4 == 0:
  print("YES")
else:
  print("NO")