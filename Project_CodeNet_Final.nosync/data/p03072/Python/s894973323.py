N = int(input())
H = [int(x) for x in input().split()]
ans = 0
for i in range(N):
    c = max(H[:i+1])
    if c == H[i]:
        ans += 1
print(ans)