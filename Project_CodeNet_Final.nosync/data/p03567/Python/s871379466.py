# coding: utf-8
# Here your code !
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct  9 22:12:40 2017

@author: kitagenbakurou
"""
import numpy as np
import copy

s = input()

flag = False
for i in range(len(s) - 1) : 
    if s[i:(i+2)] == "AC" : 
        flag = True
        break

if flag : print("Yes")
else : print("No")