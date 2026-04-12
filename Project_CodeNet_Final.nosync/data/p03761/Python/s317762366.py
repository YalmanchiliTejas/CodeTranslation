n=int(input())

abc="abcdefghijklmnopqrstuvwxyz"

cnt=[[0]*n for _ in range(26)]

for i in range(n):
    temp=input()
    for j in range(26):
        cnt[j][i]=temp.count(abc[j])

ans=[]

for i in range(26):
    for j in range(min(cnt[i])):
        ans.append(abc[i])

print("".join(ans))