N = int(input())
H = list(map(int, input().split()))

ans = N
for i in range(N):
    for j in H[:i]:
        if H[i] < j:
            ans -= 1
            break

print(ans)
