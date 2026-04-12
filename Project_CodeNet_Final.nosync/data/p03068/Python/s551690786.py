n,s,k=int(input()),input(),int(input()) #入力を順番に一気に定義する
A=s[k-1]
for i in range(n):
    if s[i]!=A:
        s=s.replace(s[i],'*')
print(s)