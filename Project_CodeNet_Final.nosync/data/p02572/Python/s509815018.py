n = int(input())
a = list(map(int, input().split()))

'''
a b c d e

ab + ac + ad + ae + bc + bd + be + cd + ce + de
=
a(b+c+d+e) + b(c+d+e) + c(d+e) + d(e)
=
(a+b+c+d)e + (a+b+c)d + (a+b)c + a(b)
'''
l = 0
s = 0
for i in range(n-1):
    l += a[i]
    s += l*a[i+1]
    s %= 1000000007
print(s)
