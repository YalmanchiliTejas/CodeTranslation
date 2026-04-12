N= int(input())
moji = list(input())
K= int(input())
S=moji[K-1]
for i in range(N):
    if(moji[i]==S):
        pass
    else:
        moji[i]="*"
moji2=str("".join(moji))
print(moji2)