while True:
    n=input()
    if n==0:
        break
    board=[[0]*n for unused in xrange(n)]
    y,x=n/2+1,n/2
    board[y][x]=1
    for i in xrange(2,n*n+1):
        ny,nx=(y+1)%n,(x+1)%n
        while True:
            if board[ny][nx]==0:
                y,x=ny,nx
                break
            else:
                ny,nx=(ny+1)%n,(nx+n-1)%n
        board[y][x]=i
        
    for i in xrange(n):
        print "".join(map(lambda s:str(s).rjust(4),board[i]))