S = input()
cnt = 0
for i in range(3):
  if S[i] == 'A':
    cnt = cnt +1
 
if cnt == 3 or cnt == 0:
  print('No')
else:
  print('Yes')