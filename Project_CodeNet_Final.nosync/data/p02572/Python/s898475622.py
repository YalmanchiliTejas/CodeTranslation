import sys
n = int(sys.stdin.readline().rstrip("\n"))
a = [int(s) for s in sys.stdin.readline().rstrip("\n").split()]
p = 10**9+7
s = 0
s_2 = 0
for i in a:
    s += i
    s = s % p
    s_2 += i*i
    s_2 = s_2 % p
ans = ((s**2 - s_2) % p)*(2**(p-2)) % p
print(ans)