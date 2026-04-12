#(38)ICP得点集計ソフトウェア
while True:
    n=int(input())
    
    if n==0:
        break
    
    s=[int(input()) for i in range(n)]
    
    a=max(s)
    b=min(s)
    c=sum(s)
    y=(c-a-b)//(n-2)
    
    print(y)
