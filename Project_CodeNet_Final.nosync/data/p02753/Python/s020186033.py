S = list(input())

result = True

for i in range(len(S)-1):
   
    if S[i] != S[i+1]:
        result = True
        break
    elif S[i] == S[i+1]:
        result = False


if result == False:
    print("No")
else:
     print("Yes")