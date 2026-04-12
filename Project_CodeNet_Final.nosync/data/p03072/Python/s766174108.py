N = int(input())
H = list(map(int,input().split()))

ans = 1
mx = H[0]

for i in range(1,N):
    if H[i]>=mx:
        ans +=1
        mx =H[i]
print(ans)