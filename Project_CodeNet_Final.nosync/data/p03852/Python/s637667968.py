from sys import stdin

s = stdin.readline().rstrip()

if s in "aeiou":
    print("vowel")
else:
    print("consonant")