# -*- coding: utf-8 -*-

n = int(input())
s = list(input())
a = int(input())

del_char = s[a-1]

for i in range(len(s)):
    if(s[i] == del_char):
        continue
    else:
        s[i] = "*"

print("".join(s))