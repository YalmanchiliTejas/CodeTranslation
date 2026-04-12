import itertools
n = int(input())
a = list(map(int,input().split()))
ruisekiwa = [0] * n
cnt = 0
ruisekiwa[0] = a[0]
for i in range(1,n):
    ruisekiwa[i] = ruisekiwa[i-1] + a[i]
for i in range(n):
    cnt += a[i] * (ruisekiwa[-1] - ruisekiwa[i])
print(cnt % (10**9 + 7))