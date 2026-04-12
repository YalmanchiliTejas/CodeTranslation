N=int(input())
S=list(input())
K=int(input())

letter=S[K-1]
for i in range(len(S)):
    if S[i]!=letter:
        S[i]="*"
        
word="".join(S)
print(word)