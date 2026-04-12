# -*- coding: utf-8 -*-

s = list(input())

output = "No"
for i in range(len(s) - 1):
    if(s[i] == 'A'):
        if(s[i+1] == 'C'):
            output = "Yes"
            break

print(output)