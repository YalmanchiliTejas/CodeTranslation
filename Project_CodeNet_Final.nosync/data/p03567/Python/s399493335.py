s = input()
c = 0

for i in range(len(s)):
  if s[i] == 'A':
    if s[i+1] == 'C':
      c += 1
      break

if c > 0:
  print('Yes')
else:
  print('No')