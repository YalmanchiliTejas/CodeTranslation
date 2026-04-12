# -*- coding: utf-8 -*-
# Input of 3 stations
stations = input() # i.e. ABA

def needBus(s):
  '''<str> s: 3 stations'''
  if ((s[0] != s[1]) or (s[1] != s[2])):
    return 'Yes'
  else:
    return 'No'
  
# Output
print(needBus(stations))
