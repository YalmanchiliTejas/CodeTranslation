N = int(input())
H = list(map(int, input().split()))
res = 1
for i in range(1,N):
    if max(H[0:i]) <= H[i]:
        res += 1
print(res)