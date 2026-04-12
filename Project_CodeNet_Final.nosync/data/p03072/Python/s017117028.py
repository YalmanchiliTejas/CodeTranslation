n = int(input())
h = list(map(int,input().split()))
ans = 1

for i in range(2,n+1):
    if max(h[:i])==h[i-1]:
        ans += 1

print(ans)