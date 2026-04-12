ma = lambda :map(int,input().split())
ni = lambda:int(input())
import collections
import math
import itertools
import heapq as hq
gcd = math.gcd
n = ni()
A = []
for i in range(n):
    A.append(ni())
A.sort()
A1 = A[:(n+1)//2]
A2 = A[(n+1)//2:]
#print(A1,A2)


if n%2==0:
    print(2*sum(A2) - 2*sum(A1) - A2[0] + A1[-1])

else:
    s1 = 2*sum(A2) - 2*sum(A1) + A1[-1]+A1[-2] #a1がa2より多い場合
    A1 = A[:n//2]
    A2 = A[n//2:]
    s2 = 2*sum(A2)  - 2*sum(A1) -A2[0] -A2[1]#a2がa1より多い場合
    print(max(s1,s2))
