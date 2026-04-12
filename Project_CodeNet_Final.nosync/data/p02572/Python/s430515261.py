import itertools
n = int(input())
a = list(map(int,input().split()))
a_c = list(itertools.accumulate(a))
MOD = 10**9 + 7
cnt = 0

for i in range(n):
    temp = a[i] * (a_c[-1] - a_c[i])
    cnt += temp

print(cnt % MOD)
