from sys import stdin

c = stdin.readline().rstrip()
if c in ["a", "i", "u", "e", "o"]:
  print("vowel")
else:
  print("consonant")