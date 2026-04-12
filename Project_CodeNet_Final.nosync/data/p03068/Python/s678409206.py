N=int(input())
S=input()
K=int(input())
count=0
for s in S:
    if s==S[K-1]:
        pass
    else:
        S=S[:count] + '*' + S[count+1:]
    count+=1
print(S)