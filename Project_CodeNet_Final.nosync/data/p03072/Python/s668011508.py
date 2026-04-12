n = int(input())
h = [0] + list(map(int, input().split()))
ans = 0

for i in range(1, n+1):
    if h[i] == max(h[:i+1]):
        ans += 1

print(ans)
