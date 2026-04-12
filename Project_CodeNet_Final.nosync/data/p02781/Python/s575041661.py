import math
import sys
sys.setrecursionlimit(1000010)

SN = input()
N = int(SN)
K = int(input())
# print(N,K)

m = [[0,0,0,0]]
s = [ 1, 9, 0, 0 ]
m.append(s)
#print(m) 


for i in range(2,101):
    t = [s[0], s[0]*9 + s[1], s[1]*9 + s[2], s[2]*9 + s[3] ]
    s = t
    m.append(s)

# print(m)


def count(n,k):
    if n ==0:
        if k == 0:
            return 1
        else:
            return 0
    if n < 10:
        if k == 0:
            return 1
        elif k == 1:
            return n
        else:
            return 0
    if k == 0:
        return 1

    if n < 10 ** (k-1):
        return 0
        
    t = n 
    p = 1 
    q = 0
    while t >= 10:
        t = t //10
        p = p * 10
        q = q + 1 
    # Saijoui 0 : 00000-09999
    #print("t,q", t,q)
        
    ans = m[q][k]
    #print(n,k, "#1", ans)
    # Saijoun 1-(t-1): x0000-x9999
    #print(n,k,"#2",(t-1)* m[q][k-1])
    ans = ans + (t-1)* m[q][k-1]

    # Saijoui t: t0000-tbcdrf
    remain = n - p * t 
    x = count(remain,k-1)
    #print(n,k, "#3", x)
    ans = ans + x
    # print(n,k,"#4",ans)
    return ans

print(count(N,K))


