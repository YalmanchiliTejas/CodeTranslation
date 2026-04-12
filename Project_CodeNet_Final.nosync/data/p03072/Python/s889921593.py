N = int(input())
H = [int(i) for i in input().split()]
ans = 1
for i in range(1, N):
    for j in range(i):
        if H[i] < H[j]:
            break
    else :
        ans += 1

print(ans)