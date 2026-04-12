n=int(input())
h=list(map(int,input().split()))
cnt=0
maxi=0
for x,i in enumerate(h):
    maxi=max(maxi,h[x])
    if i>=maxi:
        cnt+=1
print(cnt)