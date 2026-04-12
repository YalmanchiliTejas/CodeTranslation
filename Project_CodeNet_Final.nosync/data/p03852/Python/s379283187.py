l = str(input())

c = 0

for i in range(len(l)):
  if l[i] == "a":
    c += 1
  elif l[i] == "e":
    c += 1
  elif l[i] == "i":
    c += 1
  elif l[i] == "o":
    c += 1
  elif l[i] == "u":
    c += 1
  else:
    c +=0

if c > 0:
  print("vowel")
else:
  print("consonant")