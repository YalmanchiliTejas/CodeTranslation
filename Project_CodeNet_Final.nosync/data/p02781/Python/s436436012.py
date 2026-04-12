from bisect import *
from collections import *
from fractions import gcd
from math import factorial
def permutations_count(n, r):
    if not n>=r>=0:
        return(0)
    else:
        return factorial(n) // factorial(n - r)
def combinations_count(n, r):
    if not n>=r>=0 or n<0:
        return(0)
    elif r==0:
        return(1)
    else:
        return factorial(n) // (factorial(n - r) * factorial(r))
N=input()
K=int(input())
length=len(str(N))
count=0
count3=0
flag=1
for i in range(length):
    if N[i]!="0":
        if K-count3 >=1:count+=combinations_count(length-1-i,K-count3)*(9**(K-count3))
        if K-count3-1 >=0:count+=combinations_count(length-1-i,K-count3-1)*(9**(K-1-count3))*(int(N[i])-1)
        count3+=1
    if K-count3==0:
        count+=1
        #count+=int(N[i])
        break
print(count)
