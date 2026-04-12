N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(1,N):
    flg = True
    for j in range(i):
        if(H[i] >= H[j]):
            continue
        else:
            flg = False
            break
    if flg:
        ans += 1

print(ans)