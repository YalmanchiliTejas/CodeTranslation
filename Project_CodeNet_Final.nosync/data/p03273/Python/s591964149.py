H,W=map(int, input().split())
s=[]
for _ in range(H):
    s.append(list(input()))
x = []
y = []
for i in range(len(s)):
    if set(s[i])=={"."}: #残すのはset(i)==2
        x.append(i)
for i in range(len(s[0])):
    y_check = []
    for j in range(len(s)):
        y_check.append(s[j][i])
    if set(y_check)=={"."}:
        y.append(i)
for i in x[::-1]:
    del s[i]
for j in range(len(s)):
    for i in y[::-1]:
        del s[j][i]
for i in s:
    for j in i:
        print(j,end="")
    print("")