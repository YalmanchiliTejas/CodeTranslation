a=int(input())
b = list(map(int, input().split()))
b.sort()
S=0
c=sum(b)
for i in range(0,a):
    c=c-b[i]
    S=S+b[i]*c
print(S % (10**9+7))