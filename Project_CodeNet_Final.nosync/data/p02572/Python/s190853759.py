n = int(input())
a = list(map(int,input().split()))

mm = 10**9 + 7

def cumsum(a):
    s = [0]
    for i in range(len(a)):
        s.append(s[i]+a[i])
    return s

S = cumsum(a)

ans = 0
for i in range(n):
    ans += a[i]*S[i]
print(ans % mm)