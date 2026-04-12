#WA

#桁DP

N=str(input())
K=int(input())
L=len(N)

#DP[i][smaller][j]=上からi桁(1<=i<=L)で0でない数字がj個(0<=j<=3)
DP=[[[0]*5 for index1 in range(2)] for index2 in range(L+1)]
#適当に初期設定
DP[0][0][0]=1



for i in range(1,L+1):
    #smaller=1->smaller=1
    DP[i][1][4]+=DP[i-1][1][4]*10+DP[i-1][1][3]*9
    DP[i][1][3]+=DP[i-1][1][3]+DP[i-1][1][2]*9
    DP[i][1][2]+=DP[i-1][1][2]+DP[i-1][1][1]*9
    DP[i][1][1]+=DP[i-1][1][1]+DP[i-1][1][0]*9
    DP[i][1][0]+=DP[i-1][1][0]

    n=int(N[i-1])

    #smaller=0->smaller=1
    #n=0だとsmaller=0->smaller=1がない
    #n=1だとsmaller=0->smaller=1のとき必ずjは変化しない
    if n==1:
        DP[i][1][4]+=DP[i-1][0][4]
        DP[i][1][3]+=DP[i-1][0][3]
        DP[i][1][2]+=DP[i-1][0][2]
        DP[i][1][1]+=DP[i-1][0][1]
        DP[i][1][0]+=DP[i-1][0][0]
    elif n>=2:
        DP[i][1][4]+=DP[i-1][0][4]*n+DP[i-1][0][3]*(n-1)
        DP[i][1][3]+=DP[i-1][0][3]+DP[i-1][0][2]*(n-1)
        DP[i][1][2]+=DP[i-1][0][2]+DP[i-1][0][1]*(n-1)
        DP[i][1][1]+=DP[i-1][0][1]+DP[i-1][0][0]*(n-1)
        DP[i][1][0]+=DP[i-1][0][0]

    #smaller=0->smaller=0
    #n=0だと必ずjは変化しない
    if n==0:
        DP[i][0][4]+=DP[i-1][0][4]
        DP[i][0][3]+=DP[i-1][0][3]
        DP[i][0][2]+=DP[i-1][0][2]
        DP[i][0][1]+=DP[i-1][0][1]
        DP[i][0][0]+=DP[i-1][0][0]
    else:
        DP[i][0][4]+=DP[i-1][0][4]+DP[i-1][0][3]
        DP[i][0][3]+=DP[i-1][0][2]
        DP[i][0][2]+=DP[i-1][0][1]
        DP[i][0][1]+=DP[i-1][0][0]

print(DP[L][0][K]+DP[L][1][K])

