h,w = map(int,input().split())
a = []
for i in range(h):
    s=list(input())
    if s.count('#')!=0:
        a.append(s)



for i in range(len(a[0])):
    k = 0
    for j in range(len(a)):
        if a[j][i] == '.':
            k += 1
    if k == len(a):
        for j in range(len(a)):
            a[j][i] = 'a'
    k = 0
#print(a)

for i in range(len(a)):
    ans = ''
    for j in range(len(a[0])):
        if a[i][j] != 'a':
            ans += a[i][j]
    print(ans)
    
