n=int(input())
k=int(input())
dp0=[[0 for i in range(4)] for i in range(len(str(n))+1)]
dp1=[[0 for i in range(4)] for i in range(len(str(n))+1)]

for i in range(1,len(str(n))+1):
    dp0[i][0]=1
dp0[1][1]=int(str(n)[0])-1
dp1[1][1]=1

for N in range(2,len(str(n))+1):
    for num in range(10):
        for K in range(1,4):
            if num!=0:
                if num<int(str(n)[N-1]):
                    dp0[N][K]+=dp0[N-1][K-1]+dp1[N-1][K-1]
                elif num==int(str(n)[N-1]):
                    dp0[N][K]+=dp0[N-1][K-1]
                    dp1[N][K]+=dp1[N-1][K-1]
                else:
                    dp0[N][K]+=dp0[N-1][K-1]
            else:
                if int(str(n)[N-1])>0:
                    dp0[N][K]+=dp0[N-1][K]+dp1[N-1][K]
                elif int(str(n)[N-1])==0:
                    dp1[N][K]+=dp1[N-1][K]
                    dp0[N][K]+=dp0[N-1][K]
#print(dp0)
#print(dp1)
print(dp1[-1][k]+dp0[-1][k])
