import math
import numpy as np

n = int(input())
S=[]

for i in range(n):
    S.append(str(input()))
    

def Count_Alphabet(word):
    global alphabet
    string = str(word)
    alphabet=str("abcdefghijklmnopqrstuvwxyz")
    count = np.zeros(len(alphabet))
    
    for i in range(0,len(alphabet)):
        for j in range(0,len(string)):
            if alphabet[i] == string[j]:
                count[i] += 1    
    return count

cout = []

for i in range(n):
    cout.append(Count_Alphabet(str(S[i])))
    



ans = str()

for i in range(len(alphabet)):
    ith = []
    for j in range(n):
        ith.append(cout[j][i])
        
    min_i = min(ith)
    ans = ans + str(alphabet[i])*int(min_i)
    
print(ans)