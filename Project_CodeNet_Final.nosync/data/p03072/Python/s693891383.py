N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(1,N):
    highest = max(H[:i])
    if H[i] >= highest:
        ans += 1
print(ans)