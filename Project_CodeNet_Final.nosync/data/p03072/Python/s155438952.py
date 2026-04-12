N = int(input())
H = list(map(int,input().split()))

res=0

Hmax = max(H)
Hmax_idx = 0
localmax=H[0]
for idx,h in enumerate(H):
    if h >= localmax:
        localmax = h
        res+=1
    else:
        continue
    

    if h == Hmax:
        Hmax_idx = idx
        break

if Hmax_idx+1 < N:
    for i in range(idx+1,N):
        if H[i] >= Hmax:
            res+=1

print(res)
