import sys
input = sys.stdin.readline

#n = int(input())
#l = list(map(int, input().split()))

'''
a=[]
b=[]
for i in range():
    A, B = map(int, input().split())
    a.append(A)   
    b.append(B)'''
n=int(input())
a=list(map(int, input().split()))
ans=0
anss=[0]*(n+1)
for i in range(1,n+1):
    anss[-i-1]=anss[-i]+a[-i]
    if anss[-i-1]>10**9+7:
        anss[-i-1]%=10**9+7
#print(anss)
for i in range(n-1):
    ans+=a[i]*anss[i+1]
    if ans>10**9+7:
        ans%=10**9+7
print(ans)