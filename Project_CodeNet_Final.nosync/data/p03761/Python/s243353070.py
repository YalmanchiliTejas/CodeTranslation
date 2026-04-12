import itertools
from collections import Counter
n=int(input())
S = [list(input()) for i in range(n)]
tmp=S[0]
for i in range(1,n):
    tmp=list((Counter(S[i]) & Counter(tmp)).elements())

print(''.join(sorted(tmp)))