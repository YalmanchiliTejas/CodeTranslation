import sys
input = sys.stdin.readline

N=int(input())
S=tuple(map(int,input().split()))
T=tuple(map(int,input().split()))
U=tuple(map(int,input().split()))
V=tuple(map(int,input().split()))

ANS=[[[-1]*N for i in range(N)] for b in range(64)]

for b in range(64):
    for i in range(N):
        if S[i]==0 and (1<<b) & U[i]!=0:
            for j in range(N):
                if ANS[b][i][j]==0:
                    print(-1)
                    sys.exit()
                ANS[b][i][j]=1

        if S[i]==1 and (1<<b) & U[i]==0:
            for j in range(N):
                if ANS[b][i][j]==1:
                    print(-1)
                    sys.exit()
                ANS[b][i][j]=0


        if T[i]==0 and (1<<b) & V[i]!=0:
            for j in range(N):
                if ANS[b][j][i]==0:
                    print(-1)
                    sys.exit()
                ANS[b][j][i]=1

        if T[i]==1 and (1<<b) & V[i]==0:
            for j in range(N):
                if ANS[b][j][i]==1:
                    print(-1)
                    sys.exit()
                ANS[b][j][i]=0

for rep in range(2):
    for b in range(64):
        for i in range(N):
            if S[i]==0 and (1<<b)& U[i]==0:
                count_mi1=0
                okflag=0
                for j in range(N):
                    if ANS[b][i][j]==0:
                        okflag=1
                        break
                    if ANS[b][i][j]==-1:
                        count_mi1+=1
                        if count_mi1>=2:
                            break
                    
                if okflag==0 and count_mi1==0:
                    print(-1)
                    sys.exit()

                if okflag==0 and count_mi1==1:
                    for j in range(N):
                        if ANS[b][i][j]==-1:
                            ANS[b][i][j]=0
                            break

            if S[i]==1 and (1<<b) & U[i]!=0:
                count_mi1=0
                okflag=0
                for j in range(N):
                    if ANS[b][i][j]==1:
                        okflag=1
                        break
                    if ANS[b][i][j]==-1:
                        count_mi1+=1
                        if count_mi1>=2:
                            break
                    
                if okflag==0 and count_mi1==0:
                    print(-1)
                    sys.exit()

                if okflag==0 and count_mi1==1:
                    for j in range(N):
                        if ANS[b][i][j]==-1:
                            ANS[b][i][j]=1
                            break

            if T[i]==0 and (1<<b)& V[i]==0:
                count_mi1=0
                okflag=0
                for j in range(N):
                    if ANS[b][j][i]==0:
                        okflag=1
                        break
                    if ANS[b][j][i]==-1:
                        count_mi1+=1
                        if count_mi1>=2:
                            break
                    
                if okflag==0 and count_mi1==0:
                    print(-1)
                    sys.exit()

                if okflag==0 and count_mi1==1:
                    for j in range(N):
                        if ANS[b][j][i]==-1:
                            ANS[b][j][i]=0
                            break

            if T[i]==1 and (1<<b) & V[i]!=0:
                count_mi1=0
                okflag=0
                for j in range(N):
                    if ANS[b][j][i]==1:
                        okflag=1
                        break
                    if ANS[b][j][i]==-1:
                        count_mi1+=1
                        if count_mi1>=2:
                            break
                    
                if okflag==0 and count_mi1==0:
                    print(-1)
                    sys.exit()

                if okflag==0 and count_mi1==1:
                    for j in range(N):
                        if ANS[b][j][i]==-1:
                            ANS[b][j][i]=1
                            break

for i in range(N):
    for j in range(N):
        S=[]
        for b in range(63,-1,-1):
            if ANS[b][i][j]==-1:
                S.append((i+j)%2)
            else:
                S.append(ANS[b][i][j])

        print(int("".join(map(str,S)),2),end=" ")
    print()
