n = int(input())

a = [list(input()) for i in range(n)]

b = [[0]* 26 for i in range(n)]
for i in range(n):
    for j in a[i]:
        b[i][ord(j)-97] += 1
su = ""

for i in range(26):
    if min(b,key = lambda x:x[i])[i] != 0:
        su += chr(i+97)*min(b,key = lambda x:x[i])[i]
print(su)