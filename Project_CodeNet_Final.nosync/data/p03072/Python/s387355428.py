N = int(input())
H = list(map(int,input().split()))

ans = 0

for i in range(N):
    count = 0
    for j in range(i):
        if(H[i] >= H[j]):
            count += 1
    if(count == i):
        ans += 1

print(ans)
