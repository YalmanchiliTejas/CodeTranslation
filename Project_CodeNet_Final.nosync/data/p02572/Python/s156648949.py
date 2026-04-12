n = int(input())
a = list(map(int, input().split())) 

MOD = 1000000007

sum_a = sum(a) % MOD 
sum_aa = sum((ai * ai) % MOD for ai in a) % MOD

mod_inv = pow(2, -1, MOD) 

ans = ((((sum_a * sum_a) % MOD) - sum_aa) * mod_inv) % MOD

print(ans)