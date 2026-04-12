import re
n = input()
s = input()
k = input()
chlist = list(s)
ked = int(k) - 1
nonreplace = chlist[int(ked)]
for num in range(int(n)):
  #numed = num - 1
  if chlist[num] == nonreplace:
    pass
  else:
    chlist[num] = "*"
stred = ''.join(chlist)
print(stred)
