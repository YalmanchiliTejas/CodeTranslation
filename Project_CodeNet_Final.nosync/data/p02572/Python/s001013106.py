MOD = 10**9 + 7
N = int(input())

modsum = 0
A = list(map(int, input().split()))
for a in A:
    modsum = (modsum + a) % MOD

count = 0
for a in A[:-1]:
    modsum -= a
    while modsum < 0:
        modsum = MOD + modsum
    count = (count + (modsum * a) % MOD) % MOD
print(count)