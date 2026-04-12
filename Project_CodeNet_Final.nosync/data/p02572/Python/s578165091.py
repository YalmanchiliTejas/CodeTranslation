n = int(input())
a = list(map(int, input().split()))
s = [0]
for i in a:
    s.append(s[-1]+i)
ans = 0
for i in range(n):
    ans += a[i]*s[i]
    ans %= 1000000007
print(ans)