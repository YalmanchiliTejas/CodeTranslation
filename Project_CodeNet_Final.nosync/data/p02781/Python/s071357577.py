N=list(input())
K=int(input())

OK=[[0 for k in range(5)]for i in range(len(N))]
OK[0][0]=1
OK[0][1]=int(N[0])-1
D=1
#print(OK)
for i in range(1,len(N)):
    OK[i][0]=OK[i-1][0]
    OK[i][1]+=OK[i-1][0]*9+OK[i-1][1]
    OK[i][2]+=OK[i-1][1]*9+OK[i-1][2]
    OK[i][3]+=OK[i-1][2]*9+OK[i-1][3]
    if D<=K and int(N[i])!=0:
        OK[i][D]+=1
        OK[i][D+1]+=int(N[i])-1
        D+=1
if D==K:
    print(OK[-1][K]+1)
else:
    print(OK[-1][K])
