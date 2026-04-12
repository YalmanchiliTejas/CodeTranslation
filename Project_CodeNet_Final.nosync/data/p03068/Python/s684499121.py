N=int(input())
S=input()
K=int(input())
a = ''
b=S[K-1]
for s in S:
    if s==b:
        a+=b
    else:
        a+='*'
print(a)