# abc_95_c
# import sys
from sys import stdin
A, B, C, X, Y = [int(x) for x in stdin.readline().rstrip().split()]
ans1 = 0
# ans2 = 0
if C < (A/2)+(B/2):
    if X > Y:
        ans1 = C*2*min(X, Y)+(max(X, Y)-min(X, Y))*A
    else:
        ans1 = C*2*min(X, Y)+(max(X, Y)-min(X, Y))*B
else:
    ans1 = A*X+B*Y
ans2 = C*2*max(X, Y)
print(min(ans1, ans2))
