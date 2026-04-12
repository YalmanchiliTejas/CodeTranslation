alpha = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
n = int(input())
k = []
ans = ""
for _ in range(n):
    s = list(str(input()))
    ALs = [0]*26
    for i in range(len(s)):
        ALs[alpha.index(s[i])] += 1
    k.append(ALs)
for i in range(26):
    tmp = float("inf")
    for j in range(n):
        tmp = min(tmp,k[j][i])
    if tmp > 0:
        ans += alpha[i]*tmp
print(ans)