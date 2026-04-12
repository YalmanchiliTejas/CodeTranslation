N = int(input())
hn = list(map(int,input().split()))
ans = 0
for i in range(N):
    if hn[i] == max(hn[:i+1]):
        ans += 1
print(ans)