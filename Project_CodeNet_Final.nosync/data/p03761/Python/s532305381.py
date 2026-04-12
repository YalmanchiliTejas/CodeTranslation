n = int(input())
s = []
alp='abcdefghijklmnopqrstuvwxyz'
con = []
for i in range(n):
    s =input()
    for j in range(26):
        con.append(s.count(alp[j]))
    

ans = ''

for i in range(26):
    num = []
    for j in range(n):
        num.append(int(con[i+j*26]))
    ans += alp[i] * min(num)
print(ans)