N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
    tf = True
    for j in range(0, i):
        if H[j] <= H[i]:
            pass
        else:
            tf = False
    if tf == True:
        ans += 1
print(ans)
