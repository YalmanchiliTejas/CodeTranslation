s = input()
a = ''
for i in range(len(s)-1):  
  if s[i] + s[i+1] =='AC':
    a = 'Yes'
  else:
    pass

if a == 'Yes':
  print(a)
else:
  print('No')