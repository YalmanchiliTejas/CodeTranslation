N = int(input())
H = list(map(int,input().split()))

ans = N
for i in range(1,N):
    for j in range(i):
        if H[j] > H[i]:
            ans -= 1
            break
print(ans)
