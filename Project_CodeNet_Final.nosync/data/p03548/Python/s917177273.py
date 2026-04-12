a = list(map(int,input().split()))
X=a[0]
Y=a[1]
Z=a[2]
summary=0
cnt=0
tmp=X-Z

while summary<=tmp:
    summary=summary+Y+Z
    if summary<=tmp:
        cnt=cnt+1

print(cnt)
