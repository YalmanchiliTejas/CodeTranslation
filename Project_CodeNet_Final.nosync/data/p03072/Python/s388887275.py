N = int(input())
H = list(map(int, input().split()))
ans = 1
max_height = H[0]

for i in range(N-1):
    if H[i+1] >= max_height:
        ans += 1
        max_height = H[i+1]

print(ans)
