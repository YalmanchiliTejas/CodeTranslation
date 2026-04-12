n=int(input())
s=input()
k=int(input())
for S in s:print(S if S==s[k-1] else '*',end='')