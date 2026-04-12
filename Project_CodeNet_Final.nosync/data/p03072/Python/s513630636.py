N = int(input())
H = list(map(int,input().split()))
ans = N

for i in range(1, N):
    for j in range(0, i):
        if H[i] < H[j]:
            ans -= 1
            break

print(ans)