s = input()
if all("aiueo".count(c) == 1 for c in s):
  print("vowel")
else:
  print("consonant")