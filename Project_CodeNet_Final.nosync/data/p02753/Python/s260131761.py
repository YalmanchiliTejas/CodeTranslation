# coding: utf-8

# 標準入力<str>
S = input()

l = []

for i in range(3):
  l.append(S[i])

s = set(l)

if len(s) == 2:
  print("Yes")
else:
  print("No")
