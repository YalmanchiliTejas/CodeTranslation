c = input()
v = ["a", "i", "u", "e", "o"]

if all (c!=n for n in v):
  print("consonant")
else:
  print("vowel")