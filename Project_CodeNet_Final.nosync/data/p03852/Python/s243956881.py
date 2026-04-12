from sys import stdin
a = stdin.readline().strip()
b = 'aeiou'
ans = 'consonant'
if a in b:
 ans = 'vowel'
print ans