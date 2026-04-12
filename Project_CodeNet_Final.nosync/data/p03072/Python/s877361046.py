N = int(input())
H = list(map(int,input().split()))
ans = 0
for i in range(N):
    f = True
    for j in range(0,i):
        if H[j] > H[i]:
            f = False
    if f:
        ans += 1
print(ans)