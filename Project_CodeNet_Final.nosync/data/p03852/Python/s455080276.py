import re
l = input()
p = re.compile('[a-z]')

vowel = ['a', 'i', 'u', 'e', 'o']
if p.fullmatch(l):
  if l in vowel:
    print('vowel')
  else:
    print('consonant')