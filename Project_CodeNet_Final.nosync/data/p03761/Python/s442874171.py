# https://atcoder.jp/contests/abc058/tasks/arc071_a

n=int(input())
s=[sorted(input()) for _ in range(n)]
alfa=[float('inf')]*26

for e in s:
    for i in range(26):
        cnt=e.count(chr(97+i))
        alfa[i]=min(alfa[i],cnt)
ans=[]
for i in range(26):
    ans.append(chr(97+i)*alfa[i])
print(*ans,sep='')