from collections import Counter
N=int(input())
S=Counter(input())
ans=""
for i in range(N-1):
    S&=Counter(input())
for key,value in sorted(S.items()):
    ans+=key*value
print(ans)