A,B,C,X,Y=map(int,input().split())

ans=A*X+B*Y
a=0

for i in range(min(X,Y)+1):
    a=A*(X-i)+B*(Y-i)+C*i*2
    if(a<ans):
        ans=a
a=C*max(X,Y)*2
if(a<ans):
    ans=a
print(ans)