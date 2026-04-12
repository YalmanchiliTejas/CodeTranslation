#!usr/bim/python
#! -*- coding: utf-8 -*-

s = raw_input()

status = 0

for i in range(len(s)-1):
    if s[i:i+2] == "AC":
        status = 1

if status == 1:
    print "Yes"
else:
    print "No"
