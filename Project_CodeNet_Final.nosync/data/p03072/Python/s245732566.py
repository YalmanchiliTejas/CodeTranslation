
#input
#N = 4
#H = [6, 5, 6, 8]
N = int(input())
H = list(map(int,input().split()))
tmp = H[0]
ans = 0
for i in range(N):
    if H[i] >= tmp:
        ans += 1
        tmp = H[i]
print(ans)

