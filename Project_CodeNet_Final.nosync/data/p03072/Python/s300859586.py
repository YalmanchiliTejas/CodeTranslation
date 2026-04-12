n = int(input())
H = list(map(int, input().split()))
ans = 0
max = 0

for i in range(n):
    if H[i] >= max:
        max = H[i]
        ans = ans + 1

print(ans)