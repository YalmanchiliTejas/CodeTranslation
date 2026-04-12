import itertools

l = input().split(' ')

N = int(l[0])
M = int(l[1])

S = [[0 for i in range(N)]for j in range(N)]

for i in range(M):
    l = input().split(' ')
    a = int(l[0]) - 1
    b = int(l[1]) - 1 
    S[a][b] = 1
    S[b][a] = 1

seq = list(range(2,N+1))
lst = list(itertools.permutations(seq))

#print(lst)
def solve(lst):
    bef = 1
    for k in lst:
        if S[bef-1][k-1] == 1:
            bef = k
        else:
            return False

    return True


ans = 0
for list in lst:
    if solve(list):
        ans += 1

print(ans)



