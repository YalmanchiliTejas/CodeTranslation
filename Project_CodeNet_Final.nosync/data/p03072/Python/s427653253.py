N=int(input())
H= [int(h) for h in input().split()]
Hmax=[]
for n in range(N):
    Hmax.append(max(hi for i,hi in enumerate(H) if i<=n))


print(sum(Hmax[i]<=H[i] for i in range(N)))
