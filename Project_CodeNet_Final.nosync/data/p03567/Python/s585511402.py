s = input()
p = s[0]
for i in s[1:]:
  if p+i == 'AC':
    print('Yes')
    exit()
  p = i
print('No')