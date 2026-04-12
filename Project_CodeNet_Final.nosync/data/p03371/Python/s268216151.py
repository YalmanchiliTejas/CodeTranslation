import math
import copy
from queue import Queue
import heapq
import numpy as np

MOD = 5000000007

#n = int(input())
#b = int(input())
a, b, c, x, y = [int(i) for i in input().split()]
#table = [[int(i)  for i in input().split()] for j in range(m)]
#table = [list(input()) for n in range(r)] #table[h][w]
#p = [int(i) for i in input().split()]
#s = [int(i) for i in range(n)]
#p = [int(input()) for i in range(m)]
#s = input()

#list = list(s)
#dp = [MOD for _ in range(m)]
#dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
#dp = [[[0 for _ in range(11)] for _ in range(2)] for _ in range(11)]

#Combination = [[0 for _ in range(n+1)] for _ in range(n+1)]
#b = [[0 for _ in range(n+1)] for _ in range(n+1)]

kotae = 1000000001
if (x > y):
    max = x
else:
    max = y
for i in range(0,max+1):
    j = x - i
    k = y - i
    if(j < 0):
        j = 0
    if(k < 0):
        k = 0
    temp = a * j + b * k + 2 * c * i
    if (temp < kotae):
        kotae = temp

print(kotae)