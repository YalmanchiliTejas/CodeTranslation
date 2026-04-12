while 1:
    t,(n,m)=[0],map(int,input().split())
    if n==m==0:break
    if n:t+=map(int,input().split())
    if m:t+=map(int,input().split())
    t.sort()
    print(max(t[i+1]-t[i] for i in range(n+m)))