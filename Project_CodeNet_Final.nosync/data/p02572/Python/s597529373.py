N = int(input())
a = list(map(int, input().split()))

## 高々 N(N-1)/2　< 2 * 10^10 のため何とかなる...?
mod = 10**9 + 7

'''
sum = 0
for i in range(N-1):
    for j in range(i+1,N):
        sum += a[i]*a[j]

ans = sum % mod
print(ans)
'''

### a1　は a2~an(= S)までの和を必要とする. a2 は S - a2 (=S). a3 は S - a3...

s = 0
for i in range(N):
    s += a[i]

sum = 0
for i in range(N-1):
    s -= a[i]
    sum += a[i]*s

ans = sum % mod
print(ans)