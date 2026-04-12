N = int(input())
H = [0]
H += list(map(int, input().split()))

ans = 0

for i in range(1, N + 1) :
    judge = True
    for j in range(i) :
        if H[i] < H[j] :
            judge = False
            break
    if judge :
        ans += 1

print(ans)
