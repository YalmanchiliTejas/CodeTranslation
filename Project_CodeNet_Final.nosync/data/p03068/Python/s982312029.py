def gcd_core(a, b):
    if b == 0:
        return a
    else:
        return gcd_core(b, a % b)


def gcd(arr):
    g = gcd_core(arr[0], arr[1])
    for i in range(2, len(arr)):
        g = gcd_core(g, arr[i])
    return g

n = int(input())
s = input()
k = int(input())

key = s[k-1]
ans = ""
for i in range(n):
    if s[i] == key:
        ans += s[i]
    else:
        ans += "*"

print(ans)









