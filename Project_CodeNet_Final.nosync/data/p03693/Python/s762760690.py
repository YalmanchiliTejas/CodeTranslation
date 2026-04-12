r,g,b=map(int,input().split())
M=r*100+g*10+b
K=r*100
if (M-K)%4==0:
    print("YES")
else:
    print("NO")