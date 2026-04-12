n, x = map(int, input().split())
s = [1]
for i in range(n):
    s.append(s[i] * 2 + 3)
p = [1]
for i in range(n):
    p.append(p[i] * 2 + 1)
    
def f(n,x):
    if n >= 1:
        if 0 < x <= 1:
            return 0
        if 1 < x <= s[n-1]+1:
            return f(n-1,x-1)
        if x == s[n-1]+2:
            return p[n-1] + 1
        if s[n-1]+2 < x <= s[n]-1:
            return p[n-1] + 1 + f(n-1,x-s[n-1]-2)
        if x == s[n]:
            return 2*p[n-1] + 1
    if n == 0:
        if x == 1:
            return 1
        if x == 0:
            return 0
          
print(f(n,x))