N=int(input())
H=list(map(int,input().split()))

ANS=1
MAX=H[0]

for i in range(1,N):
    if H[i]>=MAX:
        ANS+=1
        MAX=max(MAX,H[i])

print(ANS)
