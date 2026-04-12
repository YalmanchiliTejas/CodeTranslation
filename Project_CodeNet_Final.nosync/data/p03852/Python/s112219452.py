from sys import stdin
c = stdin.readline().rstrip()
vowel = ['a', 'i', 'u', 'e', 'o']
if c in vowel:
  print('vowel')
else:
  print('consonant')