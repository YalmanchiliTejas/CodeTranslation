S=input()

Ans='No'

for i in range(len(S)-1):
    if S[i]!=S[i+1]:
        Ans='Yes'
        break
        
print(Ans)