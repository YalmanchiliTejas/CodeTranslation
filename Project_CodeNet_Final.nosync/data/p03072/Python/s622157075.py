N= int(input())
H = list(map(int,input().split()))
aH = [max(H[:i]) for i in range(1,N+1)]
ans=0
for i,e in zip(H,aH):
    if  i>=e : ans+=1
print(ans)