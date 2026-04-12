from statistics import mean, median,variance,stdev
import sys
import math

x = input().split()
#y = input().split()
a = []
for i in range(len(x)):
   a.append(int(x[i]))

print(int(a[0]*800-200*int(a[0]/15)))