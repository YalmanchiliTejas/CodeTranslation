n, t, e = map(int, raw_input().split())
x = map(int, raw_input().split())
ans = -1
for i in xrange(n):
    l = (t - e - 1)/x[i] + 1
    u = (t + e)/x[i]
    if l<=u:
        ans = i+1
        break
print ans