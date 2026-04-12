s=input()
k=""
for i in s:
  if k=="":
    k=i
  elif k!=i:
    k=""
    break
if k=="":
  print("Yes")
else:
  print("No")