s=[]
while True:
    N=int(input())
    if N==0:
        break
    else:
        tmp=[int(input()) for _ in range(N)]
        tmp.sort()
        tmp=tmp[1:-1]
        s.append(tmp)

for si in s:
    N=len(si)
    ans=0
    for sij in si:
        ans+=sij
    ans//=N
    print(ans)

