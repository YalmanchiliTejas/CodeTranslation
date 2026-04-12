import bisect
from collections import deque
N = int(input())
S = deque([int(input())])
for _ in range(N-1):
    a = int(input())
    ind = bisect.bisect_right(S,a)
    if S[ind-1]==a:
        ind1 = bisect.bisect_left(S,a)
        if ind1>0 and S[ind1-1]<a:
            S[ind1-1]=a
        else:
            S.appendleft(a)
    elif ind==0:
        S.appendleft(a)
    else:
        S[ind-1]=a
#     print("a,S = {}{}".format(a,S))
print(len(S))