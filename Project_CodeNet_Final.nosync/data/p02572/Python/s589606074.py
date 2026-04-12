import collections

n = int(input())

a = list(map(int,input().split()))

q = collections.deque(a)

retu = sum(a)
ans = 0

for i in range(n):
    nowA = q.popleft()
    retu -= nowA
    ans += (nowA * retu)

ans = ans % (10**9 + 7)
print(ans)