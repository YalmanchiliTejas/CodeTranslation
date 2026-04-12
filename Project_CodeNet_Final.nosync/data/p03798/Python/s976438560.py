n=int(input())
s=input()
a=['SS','WS','SW','WW']
def f(a,b,w):
    if w=='o':
        if a=='S' and b=='S':return 'S'
        elif a=='W' and b=='S':return 'W'
        elif a=='S' and b=='W':return 'W'
        else:return 'S'
    else:
        if a=='S' and b=='S':return 'W'
        elif a=='W' and b=='S':return 'S'
        elif a=='S' and b=='W':return 'S'
        else:return 'W'

for i in range(n):
    for j in range(4):a[j]+=f(a[j][i],a[j][i+1],s[i])
for i in range(4):
    if a[i][1]==a[i][n+1] and a[i][0] == a[i][n]:print(a[i][1:n+1]);exit()
print(-1)