N = int(input())
H = [int(i) for i in input().split()]
ans = 0
l = []
for i in range(N):
    l.append(H[i])
    if(max(l) <= H[i]):
        ans += 1
print(ans)