n=int(input())
l=list(map(int,input().split()))
suml=sum(l)
num=0
for i in range(n):
    num+=l[i]**2
print((suml**2-num)//2%(10**9+7))
