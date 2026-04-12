#n=int(input())
A,B,C,X,Y=map(int,input().split())
#hl=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(n)]
mn=A*X+B*Y
for i in range(max(X,Y)+1):
    mn=min(mn,2*i*C+A*max(0,X-i)+B*max(0,Y-i))

print(mn)