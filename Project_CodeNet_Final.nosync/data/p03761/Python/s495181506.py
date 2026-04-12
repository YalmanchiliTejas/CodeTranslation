n = int(input())
lstS = [input() for _ in range(n)]
alphabets = sorted(set(lstS[0]))
ans = ""


for char in alphabets:
    cntChar = min([lstS[i].count(char) for i in range(n)])
    ans += char * cntChar


print(ans)