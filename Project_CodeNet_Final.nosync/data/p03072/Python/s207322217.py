N = int(input())
H = list(map(int,input().split()))
H.insert(0,0)
lmax = 0
ans = 0
for i in range(1,N+1):
    if (lmax <= H[i]):
        lmax = H[i]
        ans += 1

print(ans)