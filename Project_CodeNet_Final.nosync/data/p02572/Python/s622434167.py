n = int(input())
a = list(map(int, input().split()))
s=0
b=[]
su=0
for i in range(1,n):
    su+=a[-i]
    b.append(su)
for j in range(2,n+1):
    s+=a[-j]*b[j-2]
    s%=(10**9+7)
print(s)
