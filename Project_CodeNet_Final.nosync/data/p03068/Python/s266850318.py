n=int(input())
s=list(input())
k=int(input())
c=s[k-1]
for i in s:
    print(i if i==c else '*',end='')