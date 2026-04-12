while True:
    N,A,B,C,X=map(int,raw_input().split())
    if N==A==B==C==X==0:break
    Y=map(int,raw_input().split())
    i=frame=0
    while frame<=10000:
        if X==Y[i]:
            i+=1
        if i==N:
            print frame
            break
        X=(A*X+B)%C
        frame+=1
    else:
        print -1