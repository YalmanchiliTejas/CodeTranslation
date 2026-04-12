import sys
import math


def MI(): return map(int,sys.stdin.readline().rstrip().split())


N,X,M = MI()

if M == 1:
    print(0)
    exit()

flag = [-1]*M
Z = [X]
flag[X] = 1
r = X
for i in range(2,M+2):
    r = r ** 2
    r %= M
    if flag[r] != -1:
        a,b = flag[r],i  # [a,b) = 循環節
        break
    else:
        flag[r] = i
        Z.append(r)

z = len(Z)
ans = 0

for i in range(a-1):
    ans += Z[i]
    
n = N-a+1
q = n//(b-a)
r = n % (b-a)

for i in range(a-1,a+r-1):
    ans += (q+1)*Z[i]
for i in range(a+r-1,b-1):
    ans += q*Z[i]

print(ans)
