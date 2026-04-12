N=int(input())
H=[int(i) for i in input().split()]
result=0
hmax=H[0]
for i in range(N):
    hmax=max(hmax,H[i])
    if H[i]>=hmax:
        result+=1
print(result)