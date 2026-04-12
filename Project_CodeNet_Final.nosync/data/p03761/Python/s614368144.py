#codng utf-8
from collections import Counter
n=int(input())

#A = ["a","b","b","c"]
#B = ["b","b","c","d"]
#C = list((Counter(A) & Counter(B)).elements())
#print(C)
L=[i for i in input()]
for i in range(n-1):
    l=[i for i in input()]
    L=list((Counter(L) & Counter(l)).elements())

L.sort()
L=''.join(L)
print(L)