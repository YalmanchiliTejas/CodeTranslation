N = int(input())
H = list(map(int, input().split()))

ans = 1

for n in range(1,N):
    if H[n] >= max(H[:n]):
        ans +=1

print(ans)