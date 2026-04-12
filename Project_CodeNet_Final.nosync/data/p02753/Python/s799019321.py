S = list(str(input()))
check = 0

for i in range(3):
  if S[i] == 'A':
    check += 1
    
if check == 0 or check == 3:
  print('No')
else:
  print('Yes')