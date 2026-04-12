N = int(input())
H = list(map(int,input().split()))

ans = 0
max_H = 0

for i in range(N):
    if H[i] >= max_H:
        ans += 1
        max_H = H[i]
        
print(ans)
