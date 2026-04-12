from collections import defaultdict

N=int(input())
S=[input() for _ in range(N)]

cnt=defaultdict(int)
for i in range(len(S[0])):
    cnt[S[0][i]]+=1

for i in range(1,N):
    tmp=defaultdict(int)
    for j in range(len(S[i])):
        tmp[S[i][j]]+=1
    for key,count in cnt.items():
        if count>tmp[key]:
            cnt[key]=tmp[key]

ans=[]
for key,count in cnt.items():
    for _ in range(count):
        ans.append(key)
ans.sort()
print("".join(ans))