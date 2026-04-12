N = int(input())
A = list(map(int, input().split()))
s = sum(A)
t = 0
for x in A:
  t += x ** 2
  
ans = (s ** 2 - t) // 2
ans = ans % (10 ** 9 + 7)
print(ans)
  