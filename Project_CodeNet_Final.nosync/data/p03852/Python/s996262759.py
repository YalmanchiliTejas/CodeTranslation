import sys
ps='aeiuo'
c=input()
for i in range(5):
  if c==ps[i]:
    print('vowel')
    sys.exit()
print('consonant')