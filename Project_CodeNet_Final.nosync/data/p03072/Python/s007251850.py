N=int(input())
h = list(map(int,input().split()))

max_tmp=0
ans=0

for i in range(N):
    if h[i] >= max_tmp:
        ans += 1
        max_tmp = h[i]

print(ans)