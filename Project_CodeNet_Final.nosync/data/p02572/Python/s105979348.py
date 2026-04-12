N = int(input())
A = list(map(int,input().split()))

s = [0]*(N+1)
for i in range(N):
    s[i+1] = s[i] + A[i]
    
cnt = 0
for j in range(N):
    cnt =  (cnt + (A[j]*(s[N] - s[j+1])))%(10**9+7)
print(cnt)