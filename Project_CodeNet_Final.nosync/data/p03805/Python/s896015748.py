#C
import itertools
N,M = map(int,input().split())
AB = [list(map(int,input().split())) for i in range(M)]

path = [(i+1) for i in range(N)]
p_list = list(itertools.permutations(path,N))

ans = 0
for pl in p_list:
    if pl[0] == 1:
        flag = 0
        for i in range(N-1):
            ab1 = [pl[i],pl[i+1]]
            ab2 = [pl[i+1],pl[i]]
            if ab1 in AB or ab2 in AB:
                pass
            else:
                flag = 1
                break
        if flag == 0:
            ans+=1
            
print(ans)