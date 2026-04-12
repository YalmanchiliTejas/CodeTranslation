n=int(input())
s=input().rstrip()
s=[i for  i in s]
k=int(input())
for i in range(n):
    if s[i]!=s[k-1]:
        s[i]='*'
print(''.join(s))