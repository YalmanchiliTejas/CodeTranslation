N = int(input())
H = input().split()
H = [int(s) for s in H]

ans = 0
tall = H[0]

for n in range(N):
    if tall <= H[n]:
        tall = H[n]
        ans += 1

print(ans)
        