N,X = map(int,input().split())

PforL = [1]
HforL = [1]
for i in range(1,51):
    PforL.append(PforL[i-1]*2+1)
    HforL.append(HforL[i-1]*2+3)

ans = 0
while 0<X:
    if(X<((HforL[N]-3)/2)+1):
        X -= 1
        N -= 1
        continue
    if(X==((HforL[N]-3)/2+1)):
        ans+=PforL[N-1]
        break
    if(X==((HforL[N]-3)/2+2)):
        ans+=PforL[N-1]+1
        break
    if(X<HforL[N]-1):
        ans += PforL[N-1]+1
        X -= 2+HforL[N-1]
        N -= 1
        continue
    if(X<=HforL[N]):
        ans += PforL[N]
        break
print(ans)
