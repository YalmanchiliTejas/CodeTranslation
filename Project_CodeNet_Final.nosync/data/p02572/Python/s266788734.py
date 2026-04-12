N = int(input())
S = list(map(int, input().split(' ')))

prod=0

law=10**9+7

sumation=sum(S)

for i in range(N):
  sumation=sumation-S[i]
  prod=prod+(S[i]*sumation)%law

print(prod%law)