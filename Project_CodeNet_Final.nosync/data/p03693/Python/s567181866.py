#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 10 05:50:12 2020

@author: baddude
"""


a, b, c = map(str, input().split())
abc = int(a + b + c)

if abc % 4 ==0 :
    print('YES')
else:
    print('NO')
