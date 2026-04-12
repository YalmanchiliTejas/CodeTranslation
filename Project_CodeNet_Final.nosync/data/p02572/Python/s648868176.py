N = int(input())
A = [int(x) for x in input().split()]
m = 10**9+7
s = sum(A)
cnt = 0
#print(mod_A)
for i in range(N) :
    s = s - A[i]
    cnt += A[i] * s
    cnt = cnt % m

print(cnt)
