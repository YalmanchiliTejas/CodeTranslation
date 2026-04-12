#coding:utf-8
s = input()
l = []
for i in s:
    l.append(i)

s_len = set(l)

if len(s_len) == 2:
    print('Yes')
else:
    print('No')
