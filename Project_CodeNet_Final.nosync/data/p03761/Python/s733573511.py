N=int(input())
S=[input() for i in range(N)]

import sys
if N==1:
    A=list(S[0])
    A.sort()
    print(''.join(A))
    sys.exit()

U=set(list('abcdefghijklmnopqrstuvwxyz'))
for i in range(N):
    U=U&set(list(S[i]))

if len(U)==0:
    print('')
    sys.exit()

U=sorted(list(U))
ans=''
for i in U:
    k=51
    for j in range(N):
        k=min(k,S[j].count(i))
    ans+=i*k

print(ans)