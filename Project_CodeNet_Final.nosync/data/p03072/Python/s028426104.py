N = int(input())
H = list(map(int,input().split()))

ans,tmp_max = 1,H[0]

for i in range(1,N):
    if H[i] >= tmp_max:
        tmp_max = H[i]
        ans += 1

print(ans)
