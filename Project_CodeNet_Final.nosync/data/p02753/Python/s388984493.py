S = list(input())
ans = 0

for i in range(0,2):
    if(S[i] != S[i+1]):
        ans = 1
        break
    else :
        ans = 0

if(ans == 1):
    print('Yes')
elif(ans == 0):
    print('No')