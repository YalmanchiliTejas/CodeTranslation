
value_index = dict()
n, x, m = map(int, input().split())
a = [0] * (m + 1)
s = [0] * (m + 2)

for i in range(m + 1):
    a[i] = x % m
    s[i+1] = s[i] + a[i]
    if i == n - 1:
        print(s[i+1])
        quit()
    if a[i] in value_index:
        break
    value_index[a[i]] = i
    x = x * x % m

l = value_index[a[i]]
r = i

loop_sum = s[r] - s[l]
loop_n = (n - l) // (r - l)
rem = (n - l) % (r - l)

ans = s[l] + loop_n * loop_sum + s[l+rem] - s[l]
print(ans)
