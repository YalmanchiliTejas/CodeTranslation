N, M = map(int, input().split())
a = [input() for i in range(N)]
counter = 0
numlist = []
delMlist = []

for i in range(N):
    #print(a[i])
    if a[i].count('#') == 0:
        delMlist.append(i)
#print(delMlist)

for i in delMlist:
    a.pop(i-counter)
    #print(a)
    counter += 1
#print('---------')
#print(a)
N = N - len(delMlist)
#print(N)
newlist = []
for i in range(N):   
    for j in range(M):
        if a[i][j] == '.' :
            numlist.append([i,j])
    newlist.append([a[i]])
llist = []
for i in range(N):
    #llist = list(a[i])
    llist.append(list(a[i]))
#print(llist)
counter1 = 0
fst = ''
delNlist = []
#print(N)
for i in range(M):
    for j in range(N):
        #print(j)
        if llist[j][i] == '.':
            counter1 += 1
        if counter1 == N:
            delNlist.append(i)
    counter1 = 0
#print(delNlist)
#print('---------')
#anslist = []
counter2 = 0
if delNlist != []:
    for h in delNlist:
        for i in range(N):
            a[i] = (a[i][:h-counter2] + a[i][h+1-counter2:])
        counter2 += 1
for i in a:
    print(i)
#print(a)  
        