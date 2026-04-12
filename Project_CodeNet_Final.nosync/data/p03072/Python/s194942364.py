N = int(input())
H = list(map(int,input().split()))
ans = 0
seen = True
for i in range(N):
    seen = True
    for j in range(i):
        if H[j] > H[i]:
            seen = False
    if seen == True:
        ans = ans + 1
print(ans)
