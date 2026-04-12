n=int(input())
s=input()
k=int(input())
for i in s:
    if i==s[k-1]:
        print(i,end='')
    else:
        print('*',end='')