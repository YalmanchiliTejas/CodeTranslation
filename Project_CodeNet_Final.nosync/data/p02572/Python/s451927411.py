N = int(input())
A = list(map(int,input().split()))
mod = 1000000007
sum_A = (sum(A)**2) % mod
B = list(map(lambda x: (x**2)% mod,A))
sum_B = sum(B) % mod
print(((sum_A-sum_B)*500000004)%mod)