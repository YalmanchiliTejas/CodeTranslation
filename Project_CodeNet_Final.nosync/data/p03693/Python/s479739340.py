from statistics import mean, median,variance,stdev
import sys
import math

x = input().split()
#y = input().split()
a= []
for i in range(len(x)):
    a.append(int(x[i]))

if (a[0]*100+a[1]*10+a[2])%4:print("NO")
else:print("YES")