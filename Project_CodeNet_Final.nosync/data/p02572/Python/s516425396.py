mod = 1000000007
N = int(input())
A = list(map(int,input().split()))
sum_a = sum(A)
ans = 0
for a in A:
    ans += a*(sum_a-a)
    #print(sum_a-a)
ans //= 2

print(ans%mod)