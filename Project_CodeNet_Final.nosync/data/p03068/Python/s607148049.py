import sys
import math
 
ni = lambda: int(ns())
na = lambda: list(map(int, input().split()))
ns = lambda: input()

N = ni()
S = ns()
K = ni()-1
R = ""
s = S[K]
for i in range(N):
    if(S[i]!=s):
        R += "*"
    else:
        R += S[i]
print(R)

