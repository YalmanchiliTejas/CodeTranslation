input()
s=input()
k=int(input())
print(''.join(['*',i][i==s[k-1]]for i in s))