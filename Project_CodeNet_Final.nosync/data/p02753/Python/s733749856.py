chaine = input()
repA = 0
repB = 0

for i in chaine:
  if i=='A':
    repA += 1 
  else: 
    repB += 1 

if repB==3 or repA==3:
  print("No")
else:
  print("Yes")