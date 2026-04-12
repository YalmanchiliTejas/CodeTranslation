while 1:
    n=int(input())
    if n==0:break
    ans=[[0 for i in range(n)] for j in range(n)]
    y=n//2
    x=n//2-1
    for i in range(1,n**2+1):
        y=[y+1,y+1-n][y+1==n]
        x=[x+1,x+1-n][x+1==n]
        if ans[y][x]==0:ans[y][x]=str(i).rjust(4)
        else:
            y=[y+1,y+1-n][y+1==n]
            x=[x-1,x-1+n][x==0]
            ans[y][x]=str(i).rjust(4)
    for i in ans:print(''.join(map(str,i)))
