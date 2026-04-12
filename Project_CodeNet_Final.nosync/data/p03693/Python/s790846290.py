i = list(map(int,input().split(' ')))
#print(i)
word = ''
for x in i:
  word += (str(x))
  
if int(word)%4 == 0:
  print('YES')
else:
  print('NO')
  
  
  
  
  
  