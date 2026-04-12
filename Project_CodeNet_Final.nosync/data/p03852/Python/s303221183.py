c = input()
s = 0
list = ['a', 'e', 'i', 'o', 'u']
for an in list:
  if c == an:
    s += 1
if s == 1:
    print("vowel")
else:
    print("consonant")