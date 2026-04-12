n = int(input())
h = [int(x) for x in input().split()]

ans = 1
for i in range(1,n):
    if h[i] >= max(h[:i+1]):
        ans += 1

print(ans)