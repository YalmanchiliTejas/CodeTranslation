N = int(input())
H = list(map(int ,input().split()))
ans = 1

for i in range(1, N):
    if all([H[i] >= j for j in H[:i]]):
        ans += 1

print(ans)