n = int(input())
S = input()
k = S[int(input())-1]
print(*[s if s==k else '*' for s in S], sep='')
