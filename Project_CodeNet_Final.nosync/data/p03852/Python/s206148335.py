s = input()
vowel = 'aiueo'
for v in vowel:
  if (v in s):
    print('vowel')
    exit()
else:
  print('consonant')