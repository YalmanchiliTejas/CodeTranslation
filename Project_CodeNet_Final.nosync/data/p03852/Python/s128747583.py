s = input()
a = ['a', 'i', 'u', 'e', 'o']
c = 0
for b in a:
  if s == b:
    c +=1
if c == 1:
  print('vowel')
else:
  print('consonant')