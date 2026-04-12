N=int(input())
S=input()
K=int(input())
m=''
for s in S:
    if s==S[K-1]:
        m=m+s
    else:
        m=m+"*"
print(m)