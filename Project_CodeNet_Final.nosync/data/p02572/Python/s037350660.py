N,*A = map(int, open(0).read().split())
Asq=[a**2 for a in A]
S = (sum(A)**2-sum(Asq))//2
print(S%(10**9+7))