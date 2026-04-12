N=int(input())
H=list(map(int,input().split()))
ans = 1
for i in range(1,N):
    tmp = True
    for j in range(0,i):
        if H[j]>H[i]:
            tmp = False
            break
    if tmp:
        ans += 1
print(ans)
