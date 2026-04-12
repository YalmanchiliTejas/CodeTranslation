from sys import stdin

list = stdin.readline().rstrip().split()
chr = list[0]
if chr == 'a' or chr == 'i' or chr == 'u' or chr == 'e' or chr == 'o':
    print('vowel')
else:
    print('consonant')
