N = int(input())
H = [int(_) for _ in input().split()]
ans = N
for i in range(N):
    for j in range(i):
        if H[j] > H[i]:
            ans -= 1
            break
print(ans)
