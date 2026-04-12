import sys
import io
import math
import re

datalist = input().split()
num_summit = int(datalist[0])

max_height = 0
num_available_site = 0

datalist = input().split()
for num in range(num_summit):
  height = int(datalist[num])
  if height >= max_height:
      max_height = height
      num_available_site += 1

print(num_available_site)