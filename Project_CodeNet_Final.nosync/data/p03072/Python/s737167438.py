N = int(input())
H = list(map(int, input().split()))

ans = 1
max_H = H[0]
for i in range(1, len(H)):
    if H[i-1] <= H[i] and max_H <= H[i]:
        max_H = H[i]
        ans += 1

print(ans)