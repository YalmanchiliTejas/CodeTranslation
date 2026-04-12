A = int(input())
N = input().split()
ans = 1
for i in range(A-1) :
    B = N[:i+1]
    if int(N[i+1]) >= int(max(B))  :
        ans += 1
print(ans)