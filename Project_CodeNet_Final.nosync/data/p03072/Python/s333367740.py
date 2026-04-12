N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
    for j in H[:i]:
        if j <= H[i]:
            pass
        else:
            break
    else:
        ans += 1
print(ans)