
n = int(input())
l = []
for i in range(n):
    a = input()
    l.append(a)
abc = 'abcdefghijklmnopqrstuvwxyz'
x = [50] * 26
ans = []
for i in range(26):
    for j in l:
        x[i] = min(x[i], j.count(abc[i]))
for i in range(26):
    if(x[i] != 0):
        ans.append(abc[i]*x[i])
for i in range(len(ans)):
    print(ans[i],end="")
