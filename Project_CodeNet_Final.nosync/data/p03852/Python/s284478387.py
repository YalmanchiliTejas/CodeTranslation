from sys import stdin
def S(): return stdin.readline().rstrip()

s = ['a', 'i', 'u', 'e', 'o']

c = S()

if 0<s.count(c):
    print('vowel')
else:
    print('consonant')