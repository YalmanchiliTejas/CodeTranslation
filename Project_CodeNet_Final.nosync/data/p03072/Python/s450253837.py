N = int(input())
Hs = [int(i) for i in input().split()]

ans = []
for i in range(N-1, 0, -1):
    ans.append(all(Hs[i] >= Hs[j] for j in range(i-1, -1, -1)))

print(sum(ans) + 1)
