
N,X=map(int,input().split())

#レベルiにおけるそれぞれの枚数，総数
P=[1]*(N+1)
B=[0]*(N+1)
S=[1]*(N+1)

for i in range(N):
    P[i+1]=P[i]*2+1
    B[i+1]=B[i]*2+2
    S[i+1]=P[i+1]+B[i+1]
    
def rec(l,x,temp):
    if x==0:
        return temp
    if x==S[l]:
        return temp+P[l]
    if x>=2+S[l-1]:#中心を超える
        return rec(l-1,x-(S[l-1]+2),temp+P[l-1]+1)
    return rec(l-1,x-1,temp)

print(rec(N,X,0))