def check_space(y,x):
    if g[y][x]==-1:
        return True
    return False

while 1:
    n=int(raw_input())
    if n==0:break
    g=[[-1]*n for _ in xrange(n)]
    for i in xrange(1,n**2+1):
        if i==1:
            g[n/2+1][n/2]="1"
            nowy=n/2+1
            nowx=n/2
            continue
        while 1:
            if check_space((nowy+1)%n,(nowx+1)%n):
                g[(nowy+1)%n][(nowx+1)%n]=str(i)
                nowy=(nowy+1)%n
                nowx=(nowx+1)%n
                break
            else:
                nowy=(nowy+1)%n
                nowx=(nowx-1)%n
                continue
    for i in xrange(n):
        tmp=""
        for j in xrange(n):
            tmp+=g[i][j].rjust(4)
        print(tmp)