#ABC124B
N = int(input())
H = list(map(int, input().split()))
maxH = H[0]
ans = 1
for i in range(1,N):
    if maxH <= H[i]:
        ans += 1
        maxH = H[i]
print(ans)    