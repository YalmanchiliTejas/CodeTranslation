from collections import*
N=int(input())
C=Counter(list(input()))

for _ in range(N-1):
    C&=Counter(list(input()))

ans=''
for k,v in zip(C.keys(),C.values()):
    ans+=k*v

print(''.join(sorted(ans)))