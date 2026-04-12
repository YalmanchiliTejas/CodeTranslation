n=int(input())
s=input()
k=int(input())

for a in s:
    if a==s[k-1]:
          print(a,end='')
    else:
          print('*',end='')
    