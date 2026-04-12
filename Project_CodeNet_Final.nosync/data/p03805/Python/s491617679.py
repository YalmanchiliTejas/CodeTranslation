import itertools

b_lis = []
j_lis = []
N,M = map(int,input().split())
for i in range(M):
    b_lis.append(list(map(int,input().split())))
    
n_lis =list(range(2,N+1))
#print(n_lis)
count = 0
for i in itertools.permutations(n_lis):
    frag = 1
    #print(i)
    l = [1]
    l.extend(i)
    
    for k in range(N-1):
        if [l[k],l[k+1]] in b_lis or [l[k+1],l[k]] in b_lis:
            pass
            #print(k,b_lis,[l[k+1],l[k]])
        else:
            frag = 0
            break
    if frag == 1:
        count += 1
        #print(l)

print(count)
        
