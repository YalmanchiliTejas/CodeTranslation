from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
rev = list(reversed(a))
acc = list(accumulate(rev))
ans = 0
for i in range(n-1):
    ans += acc[i]*a[n-2-i]
print(int(ans%(1000000000+7)))