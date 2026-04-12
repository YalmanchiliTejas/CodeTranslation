N = int(input())
Alst = list(map(int, input().split()))
l = len(Alst)
Blst = [0]*l
k = 0
ans = 0
for i in range(l-1, 0, -1):
    k = (k + Alst[i])%(10**9 + 7)
    Blst[i] = k

for j in range(l-1):
    ans = (ans + Alst[j] * Blst[j+1])%(10**9 + 7)

print(ans)