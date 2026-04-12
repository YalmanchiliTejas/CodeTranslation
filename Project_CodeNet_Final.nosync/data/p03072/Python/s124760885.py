N = int(input())
H = list(map(int, input().split()))

a = ""
ans = N
for i in range(1, N):
    for j in range(0, i):
        if H[j] > H[i]:
            ans -= 1
            break
print(ans)