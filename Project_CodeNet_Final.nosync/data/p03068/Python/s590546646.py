N=int(input())
S=input()
K=int(input())
n=0
s=list(S)
a=s[K-1]
while True:
    if s[n] is not a:
        s[n]='*'
    n=n+1
    if n==N:
        break
mojiretu=''.join(s)
print(mojiretu)