# coding: utf-8
# Your code here!
while True:
    n=int(input())
    
    x=[]
    for i in range(n):
        s=int(input())
        x.append(s)
    
    x1=sorted(x)
    if n==0:
        break
    else:
        sum1=sum(x1)
        sum1-=x1[0]+x1[n-1]
        y=sum1//(n-2)
        
        print(y)
