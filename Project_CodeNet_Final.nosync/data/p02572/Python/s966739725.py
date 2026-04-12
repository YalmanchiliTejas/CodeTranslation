k = 10 ** 9 + 7
N = int(input())
L = list(map(int, input().split()))
S = sum(L) ** 2
for i in L:
  S -= i ** 2

print( (S // 2) % k)