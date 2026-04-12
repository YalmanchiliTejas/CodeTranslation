n = int(input())
aaa = list(map(int, input().split()))

sum_a = 0
sum_aa = 0
for a in aaa:
  sum_a += a
  sum_aa += a ** 2
  
print(((sum_a ** 2 - sum_aa) // 2) % (10 ** 9 + 7))