N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(1,N):
    check = 1
    now_height = H[i]
    for j in range(i):
        if now_height-H[j] <0:
            check = 0
    ans += check
print(ans)