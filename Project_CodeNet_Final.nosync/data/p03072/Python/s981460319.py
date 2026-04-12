N=int(input())
H = [int(i) for i in input().split()]
ans = 0
check = [0 for _ in range(N)]

for i in range(N):
    for j in range(i):
        if H[j] <= H[i]:
                check[i] = int(check[i]) + 1
    if check[i] == i:
        ans +=1

print(ans)