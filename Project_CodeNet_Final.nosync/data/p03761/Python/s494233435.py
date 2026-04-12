#coding=UTF-8

def hinden(mozit):
    kaeshi=list(range(0,26,1))
    for idx in range(0,26,1):
        kaeshi[idx]=0


    for mozi in mozit:
        ire=ord(mozi)-ord('a')
        kaeshi[ire]+=1

    return kaeshi

N=int(input())

S=[]

for idx in range(0,N,1):
    S.append(input())
    
ans=hinden(S[0])
for idx in range(1,N,1):
    tmp=hinden(S[idx])
    for idy in range(0,26,1):
        ans[idy]=min(ans[idy],tmp[idy])

#表示
ansstr=''
for idx in range(0,26,1):
    ansstr+=(chr(ord('a') + idx))*ans[idx]

print(ansstr)
