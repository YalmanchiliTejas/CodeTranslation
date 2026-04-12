n = int(input())
s = input()
k = int(input())

x=s[k-1]
ans=[]
for i in range(n):
    if s[i]!=x:
        ans.append('*')
    else:
        ans.append(x)

print(''.join(ans))