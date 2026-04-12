s = input()
p = False
for i in range(len(s)-1):
  if s[i:i+2] == 'AC': p = True
if p: print('Yes')
else: print('No')