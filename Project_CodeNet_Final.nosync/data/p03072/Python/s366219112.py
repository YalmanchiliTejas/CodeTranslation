N = int(input())
h = list(map(int,input().split()))

ans = 1
for i in range(1,N):
    if h[i] == max(h[:i+1]):
        ans += 1

print(ans)