N = int(input())
H = list(map(int,input().split()))
P = []
ans = 1
P.append(H[0])
for i in range(1,N):
    if H[i] >= max(P):
        ans += 1
    P.append(H[i])

print(ans)