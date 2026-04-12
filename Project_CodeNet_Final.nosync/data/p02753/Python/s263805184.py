x=input()
s=0
for i in range(3):
  s=s+ord(x[i])

if s==195 or s==198:
  print("No")
else:
  print("Yes")
