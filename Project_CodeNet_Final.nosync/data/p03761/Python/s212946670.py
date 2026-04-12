# -*- coding: utf-8 -*-
n = int(input())
s = []
for _ in range(n):
    default_list = [0] * 26
    sk = input()
    for i in sk:
        default_list[ord(i) - 97]+=1
    s.append(default_list)
ret = ""
for i,l in enumerate(zip(*s)):
    ret += ""+chr(i+97)*min(l)
print(ret)
