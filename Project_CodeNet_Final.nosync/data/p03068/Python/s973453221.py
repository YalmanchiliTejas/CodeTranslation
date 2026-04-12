N=int(input())
S= list(input())
K=int(input())

str = S[K-1]
for i in range(N):
    if(S[i]!=str):
        S[i]="*"
str2 =""
for i in range(N):
    str2=str2+S[i]
print(str2)
