n=input()
a = list(map(int,input().split()))
suma = sum(a)
r = 0

for i in range(0, len(a) - 1):
  suma -= a[i]
  r += a[i] * suma
print(r % (10 ** 9 + 7))