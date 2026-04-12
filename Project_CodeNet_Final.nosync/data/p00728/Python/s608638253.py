while True:
    n=int(input())
    if n==0:
        break
    a=[]
    for i in range(n):
        a.append(int(input()))
    A=max(a)
    B=min(a)
    C=sum(a)
    D=len(a)
    E=C-A-B
    F=D-2
    print(E//F)
