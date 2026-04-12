n = int(input())
alphabets = "abcdefghijklmnopqrstuvwxyz"
lstS = [input() for _ in range(n)]
lstN = []
ans = ""


for char in alphabets:
    numChar = float("inf")
    for s in lstS:
        numChar = min(numChar, s.count(char))
    lstN.append(numChar)


for char, num in zip(alphabets, lstN):
    ans += char * num
print(ans)