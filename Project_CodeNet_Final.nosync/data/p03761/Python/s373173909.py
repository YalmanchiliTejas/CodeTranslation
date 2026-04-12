N = int(input())
S = [input() for i in range(N)]

alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
ans = []
for i in alphabet:
    tmp = 1000
    for j in range(N):
        count = S[j].count(i)
        if count < tmp:
            tmp = count
    for j in range(tmp):
        ans.append(i)
    
for i in range(len(ans)):
    print(ans[i],end="")