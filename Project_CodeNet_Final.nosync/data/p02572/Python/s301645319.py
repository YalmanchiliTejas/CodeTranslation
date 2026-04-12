num = int(input(""))
val = list(map(int,input().split()))
val_sum = sum(val)
ans = 0
mod = 10**9 + 7

for i in range(num):
    val_sum = val_sum - val[i]
    ans     = val[i] * val_sum + ans
        
print(ans%mod)