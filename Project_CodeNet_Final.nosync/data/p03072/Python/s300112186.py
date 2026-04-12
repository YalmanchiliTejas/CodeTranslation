N = int(input())
H = list(map(int,input().split()))

ans = 0

for i in range(N):
    for j in range(i):
        if H[i] < H[j]:
            break
    else:
        ans += 1

print(ans)