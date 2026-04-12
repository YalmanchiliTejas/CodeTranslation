a = ""
b = list(map(int, input().split()))
for i in range(3):
  a += str(b[i])
if int(a)%4:
  print("NO")
else:
  print("YES")