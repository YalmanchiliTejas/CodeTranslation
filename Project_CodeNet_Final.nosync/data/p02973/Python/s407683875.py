import bisect
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
Q = [-a[0]]
for i in range(1,n):
    if a[i] <= -Q[-1]:
        Q.append(-a[i])
    else:
        j = bisect.bisect_right(Q,-a[i])###right
        #print(a,Q,i,j)
        Q[j] = -a[i]
    #print(i,Q)
print(len(Q))
