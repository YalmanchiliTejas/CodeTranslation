n = int(input())
a = list(map(int, input().split()))

b = [0] * n

for i in range(n):
  if i < n/2:
    b[i] = a[(n-1) - (2*i)]
  else:
    b[i] = a[2*i - n]
print(' '.join(list(map(str, b))))
