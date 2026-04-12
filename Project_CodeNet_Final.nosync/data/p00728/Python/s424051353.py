a=int(input())
while a!=0:
    M=0
    m=1000
    sam=0
    for i in range(a):
        b=int(input())
        sam+=b
        M=max(M,b)
        m=min(m,b)
    print(int((sam-M-m)/(a-2)))
    a=int(input())
