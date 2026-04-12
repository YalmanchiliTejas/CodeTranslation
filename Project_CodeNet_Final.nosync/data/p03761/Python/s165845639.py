def f(a, b):
    rslt = []
    for i in a:
      if i in b:
        rslt += i
        b.remove(i)
    return rslt

n = int(input())
s = [sorted(list(input())) for i in range(n)]
for i in range(1,n):
  s[i] = f(s[i], s[i-1])
print("".join(s[-1]))