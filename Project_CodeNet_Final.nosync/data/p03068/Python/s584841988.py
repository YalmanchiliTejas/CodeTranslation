input()
s=input()
n=int(input())
for i,c in enumerate(s):
    print(c if s[i]==s[n-1] else '*',end='')
