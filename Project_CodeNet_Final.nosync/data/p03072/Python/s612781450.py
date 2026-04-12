N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(1,N):
    hi = H[i]
    for h in H[:i]:
        if hi < h:
            break
    else:
        ans += 1
print(ans)