# -*- coding: utf-8 -*-
"""
Created on Sat Aug 25 18:21:29 2018
ABC107B
@author: maezawa
"""

h, w = list(map(int, input().split()))
lattice = []
for i in range(h):
    hi = input()
    if '#' not in hi:
        continue
    else:
        lattice.append(hi)

#print(*lattice, sep='\n')

hn = len(lattice)
rem = []
for i in range(w):
    flag = 0
    for s in lattice:
        if s[i] == '#':
            flag = 1
            break
    if flag == 0:
        rem.append(i)
        
newlattice = []

for s in lattice:
    for i in reversed(range(w)):
        if i in rem:
            if i == w:
                s = s[:i]
            else:
                s = s[:i]+s[i+1:]
    newlattice.append(s)

for s in newlattice:
    print(s)

        
        