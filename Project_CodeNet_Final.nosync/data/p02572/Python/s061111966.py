n = int(input())
L = [int(i) for i in input().split()]

sq = 0
for i in range(n):
  sq += L[i]**2

tmp = (pow(sum(L),2) - sq) // 2
print(tmp % (pow(10,9)+7))