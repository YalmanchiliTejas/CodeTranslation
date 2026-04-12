left = {"q":True, "w":True, "e":True, "r":True, "t":True, "a":True, "s":True, "d":True, "f":True, "g":True, "z":True, "x":True, "c":True, "v":True, "b":True}
while True:
  s = raw_input()
  if s == "#" : break
  counter = 0
  is_left = True
  for i in xrange(len(s)):
    judge = s[i] in left
    if i != 0 and not is_left == judge:
      counter += 1
    is_left = judge
  print counter