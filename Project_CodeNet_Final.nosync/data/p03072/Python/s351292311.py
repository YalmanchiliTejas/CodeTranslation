n=int(input())
h = list(map(int, input().split()))

ans=0
last=-1
for tmp in h:
        if last <= tmp:
                ans+=1
                last=tmp
print(ans)