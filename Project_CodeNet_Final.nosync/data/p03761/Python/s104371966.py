from collections import Counter

n=int(input())
C=[Counter() for i in range(n)]
for i in range(n):
    C[i]=Counter(input())

abc=[chr(i) for i in range(ord('a'),ord('a')+26)]
ans=''
for ch in abc:
    ans+=ch * min([C[i][ch] for i in range(n)])
print(ans)