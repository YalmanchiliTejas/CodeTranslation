n = int(input())
lst = list(map(int, input().split()))
s = sum(lst)
cum = 0
total = 0
mod = 10**9+7
for i in range(n):
    cum += lst[i]

    total = (total + ( lst[i]*(s - cum) ) )%mod
print(total)