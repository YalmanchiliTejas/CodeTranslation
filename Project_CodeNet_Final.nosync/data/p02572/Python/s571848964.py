N = int(input())
A = list(map(int, input().split()))
S_1 = sum(A)%(10**9+7)
S_2 = sum([a**2%(10**9+7) for a in A])
result = ((S_1**2)%(10**9+7)-S_2)%(10**9+7)
if result%2==0:
  print(result//2)
else:
  print((result+10**9+7)//2)