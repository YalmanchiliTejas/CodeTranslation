import sys
q = input()
b = ['a','i','u','e','o']
s = 'consonant'



for u in range(5):
  if q==b[u]:
    s = 'vowel'
    if s == 'vowel':
      print(s)
      sys.exit()
    
    
print(s)
    