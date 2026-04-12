import bisect
n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
q=[-1 for _ in range(n)]
for i in range(n):
    x=a[i]
    idx = bisect.bisect_left(q,x)
    q[idx-1]=x
print(n-bisect.bisect_right(q,-1))