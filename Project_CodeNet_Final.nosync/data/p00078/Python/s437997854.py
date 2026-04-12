while 1:
    n=int(input())
    if n==0:break
    c=1
    nx=ny=int((n-1)/2)
    b=[[0 for _ in range(n)] for _ in range(n)]
    ny=ny+1
    b[ny][nx]=c

    for _ in range(n*n-1):
        c+=1
        nx+=1
        ny+=1
        while 1:
            if 0<=nx<=n-1 and 0<=ny<=n-1 and b[ny][nx]==0:
                break
            if nx>n-1:
                nx=0
            if nx<0:
                nx=n-1
            if ny>n-1:
                ny=0
            if b[ny][nx]==0:
                break
            else:
                nx-=1
                ny+=1
        b[ny][nx]=c
    for i in b:
        print(("".join([str(l).rjust(4) for l in i])))

