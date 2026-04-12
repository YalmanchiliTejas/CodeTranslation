N=int(input())
H = list(map(int, input().split()))
top = H[0]
ans = 1
for i in range(N-1):
    if H[i+1]>=top:
        ans +=1
        top = H[i+1]
print(ans)