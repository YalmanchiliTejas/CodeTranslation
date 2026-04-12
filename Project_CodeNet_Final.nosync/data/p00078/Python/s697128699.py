
while 1:
    n=int(raw_input())
    if n==0:
        break
    l=[[0]*n for i in range(n)]
    x,y=n/2,n/2+1
    l[y][x]=1
    cnt=2
    while cnt<=n**2:
        x,y=(x+1)%n,(y+1)%n
        if l[y][x]==0:
            l[y][x]=cnt
            cnt+=1
        else:
            x,y=(x-1)%n,(y+1)%n
            l[y][x]=cnt
            cnt+=1
    for i in range(n):
        print ''.join(map(lambda s:str(s).rjust(4),l[i]))