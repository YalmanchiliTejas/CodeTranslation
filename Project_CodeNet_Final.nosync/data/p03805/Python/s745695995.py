import itertools
def judge(a,b,edge): #a,bがedgeで繋がっていたらTrue、いなかったらFalse
    if edge[a][b] == 1:
        return True
    else:
        return False
n,m = map(int,input().split())
edge=[[0 for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    edge[a][b] = 1
    edge[b][a] = 1
lis_permutations = itertools.permutations(range(2,n+1))
count = 0
for one_case in lis_permutations:
    one_case_1 = [1]
    for j in one_case:
        one_case_1.append(j)
    true = 1
    for i in range(len(one_case_1)-1):
        start = one_case_1[i]
        goal = one_case_1[i+1]
        if not judge(start,goal,edge):
            true = 0
            break
    if true ==1:
        count += 1
print(count)