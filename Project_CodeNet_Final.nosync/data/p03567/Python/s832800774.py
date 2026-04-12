# h,w=map(int,input().split())
s=input()

flag=False
for i in range(len(s)-1):
    if s[i] == 'A' and s[i+1]=='C':
        flag=True
print('Yes' if flag else 'No')
