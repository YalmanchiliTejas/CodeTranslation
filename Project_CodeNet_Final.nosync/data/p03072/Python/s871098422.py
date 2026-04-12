N = int(input())
H = list(map(int, input().split()))
highest = H[0]
ans = 1

for i in range(1, N):
    if highest <= H[i]:
        ans += 1
        highest = H[i]

print(ans)