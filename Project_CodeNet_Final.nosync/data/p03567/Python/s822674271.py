# -*- coding: utf-8 -*-

s = input()

flg = False
for i in range(len(s)-1):
    if(s[i:i+2] == 'AC'):
        flg = True
        
print('Yes' if flg else 'No')

    