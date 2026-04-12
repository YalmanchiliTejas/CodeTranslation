import sys
input = sys.stdin.readline
from collections import Counter,defaultdict
n=int(input())
al=[float("inf")]*26
a=ord("a")
#print(a)
for i in range(n):
    s=input().strip()
    for i in range(26):
        al[i]=min(al[i],s.count(chr(i+a)))
rep=""
for i,k in enumerate(al):
    for j in range(k):
        rep+=chr(i+a)
print(rep)
