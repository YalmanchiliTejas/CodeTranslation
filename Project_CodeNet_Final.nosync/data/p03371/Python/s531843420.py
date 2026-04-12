A,B,C,X,Y=map(int,input().split())

ans=A*X+B*Y
a=0

for i in range(max(X,Y)+1):
    a=A*max(X-i,0)+B*max(Y-i,0)+C*i*2
    if(a<ans):
        ans=a
print(ans)