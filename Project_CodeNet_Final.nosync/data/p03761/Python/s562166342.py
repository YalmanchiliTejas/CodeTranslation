n = int(input())
l = [[0]*30 for i in range(n)]
for i in range(n):
    for c in list(input()): l[i][ord(c)-97]+=1
ans = ""
for i in range(30):
    tmp = 50
    for j in range(n):tmp=min(tmp, l[j][i])
    ans += chr(i+97)*tmp
print(ans)