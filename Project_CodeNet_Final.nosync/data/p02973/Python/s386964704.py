from bisect import bisect_left as b
n=int(input())
p=[-1]*(n+1)
p[-1]=float("INF")
q=n
for i in range(n):
    x=int(input())
    d=b(p,x)-1
    q=min(q,d)
    p[d]=x
print(n-q)