N = int(input())
A = list(map(int, input().split()))
ans = 0
prev = 0
s = []
for a in A:
    now = prev + a
    s.append(now)
    prev = now

start = 0
last = s[-1]
for i in s[:-1]:
    ans += (i - start) * (last - i)
    start = i
    
    
print(ans%(10**9+7))