S = input()
sum = 0
for i in S:
  if i == 'A':
    sum += 1
if sum == 0 or sum == 3:
  print("No")
else:
  print("Yes")