"""
python3 a.py < input.txt
"""
import math
import itertools as it
import heapq

N=int(input())
H=list(map(int,input().split()))
n=0
print(len([hi for i,hi in enumerate(H) if i == 0 or (i > 0 and max(H[:i]) <= hi)]))
