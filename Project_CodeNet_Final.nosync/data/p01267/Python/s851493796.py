from collections import deque
while 1:
    n,a,b,c,x=map(int,input().split())
    if n==a==b==c==x==0:break
    y=list(map(int,input().split()))
    y_q=deque(y)
    t=0
    while t<10001:
        if x==y_q[0]:y_q.popleft()
        if len(y_q)==0:break
        t+=1
        x=(a*x+b)%c
    if t>10000:print(-1)
    else:print(t)
