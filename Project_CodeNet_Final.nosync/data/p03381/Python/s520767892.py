n = int(input())
a = sorted(zip(map(int, input().split()), range(n)))
b = [0] * n
for i in range(n//2):
  b[i], b[n - i - 1] = (a[n//2][0], a[i][1]), (a[n//2 - 1][0], a[n - i - 1][1])
print('\n'.join(map(lambda x: str(x[0]), sorted(b, key = lambda x: x[1]))))
