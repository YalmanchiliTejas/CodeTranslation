from math import factorial
N = int(input())
K = int(input())
S = list(map(int,str(N))) #桁数
ans = 0
digit = len(S)
k = K

def D(i,j): 
    if i >= j:
        return (9**j) * (factorial(i) // (factorial(i - j) * factorial(j)))
    else:
        return 0

if K > len(S):
    print(0)
    exit()

for i in range(digit):
    digit -= 1
    if int(S[i]) == 0:
        if K == len(S):
            print(0)
            exit()
        continue
    ans += D(digit,k)
    k -= 1
    if k == 0:
        ans += S[i]
        break
    ans += (int(S[i]-1))*D(digit,k)
print(ans)
