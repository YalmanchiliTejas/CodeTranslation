N,M=map(int,input().split())
#N=3
#M=7

MEMO=[[0]*(2) for i in range(N+1)]
MEMO[0][0]=1
MEMO[0][1]=1

for i in range (1,N+1):
    MEMO[i][0]=MEMO[i-1][0]*2+3
    MEMO[i][1]=MEMO[i-1][1]*2+1
t=1
s=0
n=N-1
f=0
while(True):
        if(t==M):break
        if(t+MEMO[n][0]<M):
            if f==0:
                t=t+MEMO[n][0]+1
                s+=MEMO[n][1]+1
                f+=1
            else:
                s+=MEMO[n][1]
                break
        elif(t+MEMO[n][0]>M):
            t+=1
            n-=1
            f=0
        else:
            s+=MEMO[n][1]
            break
print(s)