from sys import stdin
import math
import bisect
import heapq
import numpy as np

x,y,z = [int(x) for x in stdin.readline().rstrip().split()]

print((x-z)//(y+z))