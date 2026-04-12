from bisect import bisect_left,bisect
 
n = int(input())
p = [-1*int(input())]
for i in range(n-1):
    now = -1*int(input())
    if now >= p[-1]:
        p.append(now)
    else:
        p[bisect(p,now)] = now
print(len(p))