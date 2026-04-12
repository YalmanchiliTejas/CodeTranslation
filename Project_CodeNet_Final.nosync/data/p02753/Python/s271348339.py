s = input()
a_cnt = 0
b_cnt = 0
for i in range(3):
  if s[i] == 'A':
    a_cnt += 1
  elif s[i] == 'B':
    b_cnt += 1
if a_cnt > 0 and b_cnt > 0:
  print('Yes')
else:
  print('No')