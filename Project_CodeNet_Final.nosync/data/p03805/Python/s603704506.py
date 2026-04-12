N, M = map(int, input().split())
ab=[]
for _ in range(M):
    ab.append(tuple(map(int, input().split())))

lst=[[] for _ in range(N+1)]
for el in ab:
    lst[el[0]].append(el[1])
    lst[el[1]].append(el[0])
#print(lst)

seen=[False]*(N+1)
todo=[]


counter=0
def func(n):
    global counter
    #print(n, seen, seen.count(True), counter)
    if seen.count(True)==N:
        counter+=1
        #print(counter)

    seen[n]=True
    for val in lst[n]:
        if seen[val]==False:
            seen[val]=True
            func(val)
            seen[val]=False
func(1)
print(counter)
