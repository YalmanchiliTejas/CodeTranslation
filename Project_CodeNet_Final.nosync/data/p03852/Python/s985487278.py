a = input()
vowel = ['a','i','u','e','o']
for k in range(0,5):
  if(a == vowel[k]):
    print('vowel')
    break
else:
  print('consonant')