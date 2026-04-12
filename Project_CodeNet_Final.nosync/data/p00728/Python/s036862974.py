while True :
    
    x=int(input())
    if x==0 : break
    i=0
    b=0
    mx=0
    mn=1000
    while i<x :
        c=int(input())
        if mx<c : mx=c
        if mn>c : mn=c
        b=b+c
        i=i+1
    print(int((b-mx-mn)/(x-2)))
