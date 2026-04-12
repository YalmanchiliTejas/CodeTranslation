# -*- coding: utf-8 -*-
"""
Challenge A
"""
import numpy as np

def bus(stations):
    a = np.array(("","",""))
    for i in range(3):
        a[i] = stations[i]
    s = np.unique(a)
    if len(s)==1:
        return "No"
    elif len(s) > 1:
        return "Yes"
    else:
        return "Problem"
        
"""
my_strings = np.array(("AAA","AAB","ABA","BAA","ABB","BBA","BBB"))
for i in my_strings:
    print(i)
    print(bus(i))
"""
    
i = input()
#print(i)
print(bus(i))
