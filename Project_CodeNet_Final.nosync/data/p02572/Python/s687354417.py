n = int(input())

a = list(map(int, input().split()))
a = sorted(a, reverse=True)

sum = 0
mult = 0

for i in a:
  mult += (sum * i) 
  sum += i

print(mult % (10**9 + 7))