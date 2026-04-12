N = int(input())
H = list(map(int,input().split()))

ans = 1

for i in range (1,N):  
    if H[i] + 1  > max(H[: i + 1]):
           ans +=1

print(ans)

