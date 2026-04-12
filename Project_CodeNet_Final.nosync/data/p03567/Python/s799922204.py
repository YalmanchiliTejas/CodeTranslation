S = input()

res = 'No'
for i in range(len(S) - 1):
    if S[i] == 'A' and S[i+1] == 'C':
        res = 'Yes'
        break
        
print(res)