n=input()
k=int(input())
L=len(n)
conf=[[0 for i in range(k+1)] for j in range(L)]
conf[0][1]=int(n[0])-1
conf[0][0]=1
notconf=[[0 for i in range(k+1)] for j in range(L)]
notconf[0][1]=1
for i in range(1,L):
    if n[i]=="0":
        for j in range(k+1):
            notconf[i][j]=notconf[i-1][j]
        conf[i][0]=conf[i-1][0]
        for j in range(1,k+1):
            conf[i][j]=9*conf[i-1][j-1]+conf[i-1][j]
    else:
        looking=int(n[i])
        for j in range(1,k+1):
            notconf[i][j]=notconf[i-1][j-1]
        conf[i][0]=conf[i-1][0]
        for j in range(1,k+1):
            conf[i][j]=notconf[i-1][j]+notconf[i-1][j-1]*(looking-1)+conf[i-1][j-1]*9+conf[i-1][j]
print(notconf[-1][k]+conf[-1][k])