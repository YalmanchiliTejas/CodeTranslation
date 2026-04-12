
N = int(input())
H = list(map(int,input().split()))
ans = 1
max_H = H[0] 
for i in range(N-1):
    if H[i+1] >= max_H:
        max_H = H[i+1]
        ans += 1
print(ans)