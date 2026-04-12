N = int(input())
An_input = input().split()
An = [int(s) for s in An_input]

cnt = 0
k = 0
M = 10**9 + 7

for i in range(0, N-1):
    k += An[i]
    cnt += k * An[i+1]

ans = cnt % M
print(ans)