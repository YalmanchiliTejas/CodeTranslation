n=int(input())
s=[input() for i in range(n)]
# print(s)
jisyo=[[0]*26 for i in range(n)]
# print(jisyo)
for i in range(n):
    for j in range(len(s[i])):
        jisyo[i][ord(s[i][j])-ord("a")]+=1
# print(jisyo)
ans=[51]*26
for i in range(26):
    for j in range(n):
        ans[i]=min(ans[i],jisyo[j][i])
# print(ans)

answer=""
for i in range(26):
    for j in range(ans[i]):
        answer+=chr(i+ord("a"))
print(answer)