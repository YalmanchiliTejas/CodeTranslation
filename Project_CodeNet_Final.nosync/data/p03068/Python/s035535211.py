"""
python3 a.py < input.txt
"""
import math
import itertools as it
import heapq

N=int(input())
S=input()
K=int(input())

sk=S[K-1]
O=[]
for i in range(0,N):
    if S[i] == sk:
        O.append(S[i])
    else:
        O.append("*")

print("".join(O))
