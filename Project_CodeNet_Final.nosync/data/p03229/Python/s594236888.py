# -*- coding: utf-8 -*-
"""
Created on Sat Oct 27 19:18:58 2018
tenka1C
@author: maezawa
"""

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

a.sort()
b = [2*(-1)**i for i in range(n)]
b[0] = b[0]//2
b[-1] = b[-1]//2
b.sort()
ans1 = sum([a[i]*b[i] for i in range(n)])
c = [-b[i] for i in range(n)]
c.sort()
ans2 = sum([a[i]*c[i] for i in range(n)])
                    
print(max([ans1,ans2]))

    
    