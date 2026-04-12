N = int(input())
H = list(map(int, input().split()))

ans = 0
max_H = 0

for i in range(N):
    if max_H <= H[i]:
        max_H = H[i]
        ans += 1
        
print(ans)