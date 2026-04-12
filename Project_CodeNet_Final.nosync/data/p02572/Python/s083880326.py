N=int(input())
S=list(map(int,input().split()))
m=10**9+7
x=sum(S)%m
r=0
m=10**9+7
def div(a,b):
    return (a*pow(b,m-2,m))%m
for s in S:
    r=(r+s*(x-s))%m
print(div(r,2))