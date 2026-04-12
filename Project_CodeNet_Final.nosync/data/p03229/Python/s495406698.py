n = int(input())
a = [0] * n
for i in range(n):
  a[i] = int(input())

a.sort()

c0 = [0] * n
for i in range(n-1):
  if i%2:
    c0[i] += 1
    c0[i+1] += -1
  else:
    c0[i+1] += 1
    c0[i] += -1
    
c0.sort()

s0 = sum(i*j for i, j in zip(a, c0))
s1 = sum(-i*j for i, j in zip(a, c0[::-1]))

print(max(s0, s1))
      