#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
 
import math
import re
import sys
 
args = input().split()

X = args[0]
Y = args[1]
Z = args[2]
 
# 人数
a = (int(X)-int(Z))/(int(Y)+int(Z))
 
print(int(a))