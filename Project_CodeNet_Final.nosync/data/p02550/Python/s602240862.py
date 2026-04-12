n,x,m=map(int,raw_input().split())
i=0
v=[x]
t={x:0}
p=0 
start=0
while True: 
    i+=1
    y=(x*x)%m 
    if y in t: 
        p+=(i-t[y]) 
        start+=t[y]
        break 
    t[y]=i
    v.append(y) 
    x=y 
ans=0 

if n<(len(v)): 
    for i in range(n): 
        ans+=v[i] 
    print ans 
else: 
    for i in range(start): 
        ans+=v[i] 
    n-=(start) 
    g=n%p+start
    l=n/p 
    for i in range(start,len(v)): 
        ans+=(l*v[i]) 
        if i<g: 
            ans+=v[i] 
    print ans

    
    
