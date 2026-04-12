def f(s, t, k):
 n = len(s)
 if k > n: return 0
 a = max(t, int(s[0]))
 if a == 0: return f(s[1:], t, k)
 if k == 1: return a + (n - 1) * 9
 z = 0
 if k - 1 <= n: z += f(s[1:], 9, k)
 z += (a - 1) * f(s[1:], 9, k - 1)
 z += f(s[1:], t, k - 1)
 return z

s = input()
k = int(input())
print(f(s, 0, k))