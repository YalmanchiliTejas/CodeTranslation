N = int(input())
H = list(map(int,input().split()))
max = H[0]
ans = 1
for i in range(1,N):
    if H[i] >= max:
        ans += 1
        max = H[i]
print(ans)