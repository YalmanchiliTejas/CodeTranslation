N = int(input())
H = list(map(int,input().split()))

ans = N
for i in range(N):
    for j in range(i+1):
        if H[i]<H[j]:
            ans -= 1
            break
print(ans)